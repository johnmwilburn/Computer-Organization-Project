// DecryptData.cpp
//
// THis file uses the input data and key information to decrypt the input data
//

#include "Main.h"

// YOU WILL DELETE ALL THIS CODE WHEN YOU DO YOUR PROJECT - THIS IS GIVING YOU EXAMPLES OF HOW TO 
// ACCESS gPasswordHash AND gKey

void decryptData_01(char *data, int sized)
{
	__asm
	{
		// Starting_index[round] = gPasswordHash[0+round*4] * 256 + gPasswordHash[1+round*4];
		// index = Starting_index[round];
		// [ebp-8] <==> index
		mov	dword ptr[ebp - 4], 0x0000 // round
		mov	ah, gPasswordHash[0] // gPasswordHash[0+round*4] * 256
		mov	al, gPasswordHash[1] // gPasswordHash[1+round*4]
		mov dword ptr[ebp - 8], 0x0000 // clearing all 4 bytes of memory
		mov	word ptr[ebp - 8], ax // storing index at ebp - 8

		xor ecx, ecx 

		LOOP1:
		mov esi, [ebp + 8] // data address
		add esi, ecx // add x to data to get data[x]
		mov eax, [esi] // copy data[x] address to eax 
		
		// (#A) code table swap
		mov ebx, eax
		xor eax, eax
		mov al, bl
		lea ebx, gDecodeTable
		add ebx, eax
		mov ebx, [ebx]
		mov al, bl

		// (#C) nibble rotate right 1 
		mov dl, al
		and al, 0x0f  // bl now contains lower half of its original bits
		and dl, 0xf0  // dl now contains upper half of bl's original bits
		// rotate upper nibble right 1
		shr dl, 4
		rcr dl, 1
		lahf
		ror dl, 3
		sahf
		rcr dl, 1
		and dl, 0xF0
		// rotate lower nibble right 1
		rcr al, 1
		lahf
		ror al, 3
		sahf
		rcr al, 1
		shr al, 4
		and al, 0x0F
		// combine nibbles back into bl byte
		or al, dl

		// (#B) reverse bit order
		push ecx
		mov ecx, 8
		xor dl, dl
		REVERSEBITLOOP:
		rcr al, 1
		rcl dl, 1
		LOOP REVERSEBITLOOP
		mov al, dl
		pop ecx

		// (#E) rotate 3 bits RIGHT
		ror al, 3

		// (#D) invert bits 1,5,6 
		xor al, 0x62

		lea ebx, gkey // set ebx to address gkey
		add ebx, [ebp - 8]  // gkey[index]
		mov ebx, [ebx]
		
		xor bl, al // xor data[x] with gKey[index]

		mov[esi], bl // data[x] = data[x] ^ gKey[index];

		// loop stuff
		inc ecx
		mov edx, [ebp + 12] // set edx to dataLength
		cmp ecx, edx
		jne LOOP1
	}

	return;
} // decryptData_01


//////////////////////////////////////////////////////////////////////////////////////////////////
// EXAMPLE code to show how to access global variables
int decryptData(char *data, int dataLength)
{
	int resulti = 0;

	gdebug1 = 0;					// a couple of global variables that could be used for debugging
	gdebug2 = 0;					// also can have a breakpoint in C code

	// You can not declare any local variables in C, but can use resulti to indicate any errors
	// Set up the stack frame and assign variables in assembly if you need to do so
	// access the parameters BEFORE setting up your own stack frame
	// Also, you cannot use a lot of global variables - work with registers

	__asm {
		// you will need to reference some of these global variables
		// (gptrPasswordHash or gPasswordHash), (gptrKey or gkey), gNumRounds

		// simple example that xors 2nd byte of data with 14th byte in the key file
		lea esi,gkey				// put the ADDRESS of gkey into esi
		mov esi,gptrKey;			// put the ADDRESS of gkey into esi (since *gptrKey = gkey)

		lea	esi,gPasswordHash		// put ADDRESS of gPasswordHash into esi
		mov esi,gptrPasswordHash	// put ADDRESS of gPasswordHash into esi (since unsigned char *gptrPasswordHash = gPasswordHash)

		mov al,byte ptr [esi+0]				// get first byte of password hash
		mov al,byte ptr [esi+1]				// get 5th byte of password hash
		mov ebx,2
		mov al,byte ptr [esi+ebx]			// get 3rd byte of password hash
		mov al,byte ptr [esi+ebx*2]			// get 5th byte of password hash

		mov ax,word ptr [esi+ebx*2]			// gets 5th and 6th bytes of password hash ( gPasswordHash[4] and gPasswordHash[5] ) into ax
		mov eax,dword ptr [esi+ebx*2]		// gets 4 bytes, as in:  unsigned int X = *( (unsigned int*) &gPasswordHash[4] );

		mov al,byte ptr [gkey+ebx]			// get's 3rd byte of gkey[] data

		mov al,byte ptr [gptrKey+ebx]		// THIS IS INCORRECT - will add the address of the gptrKey global variable (NOT the value that gptrKey holds)

		mov al,byte ptr [esi+0xd];			// access 14th byte in gkey[]: 0, 1, 2 ... d is the 14th byte
		mov edi,data						// Put ADDRESS of first data element into edi
		xor byte ptr [edi+1],al				// Exclusive-or the 2nd byte of data with the 14th element of the keyfile
											// NOTE: Keyfile[14] = 0x21, that value changes the case of a letter and flips the LSB
											// Lowercase "c" = 0x63 becomes capital "B" since 0x63 xor 0x21 = 0x42
	}

	return resulti;
} // decryptData

