// EncryptData.cpp
//
// This file uses the input data and key information to encrypt the input data
//

#include "Main.h"

// YOU WILL DELETE ALL THIS CODE WHEN YOU DO YOUR PROJECT - THIS IS GIVING YOU EXAMPLES OF HOW TO 
// ACCESS gPasswordHash AND gKey

void encryptData_01(char *data, int datalength)
{
	__asm
	{
		// Starting_index[round] = gPasswordHash[0+round*4] * 256 + gPasswordHash[1+round*4];
		// index = Starting_index[round];
		// [ebp-8] <==> index
		mov	dword ptr[ebp - 4], 0x0000 // round
		mov	ah, gPasswordHash[0] // gPasswordHash[0+round*4] * 256
		mov	al, gPasswordHash[1] // gPasswordHash[1+round*4]
		mov dword ptr [ebp - 8], 0x0000 // clearing all 4 bytes of memory
		mov	word ptr [ebp - 8], ax // storing index at ebp - 8

		xor ecx, ecx
		
		LOOP1:
		mov esi, [ebp + 8] // preserving data address
		add esi, ecx // add x to data to get data[x]
		mov eax, [esi] // copy data[x] address to eax for use in xor
		
		
		lea ebx, gkey // set ebx to address gkey
		add ebx, [ebp - 8]  // gkey[index]
		mov ebx, [ebx]
		
		xor bl, al // xor data[x] with gKey[index]

		// (#D) invert bits 1,5,6 
		xor bl, 0x62 
		// (#E) rotate 3 bits LEFT
		rol bl, 3  
		
		// (#B) reverse bit order
		
		push ecx
		mov ecx, 8
		xor dl, dl
		REVERSEBITLOOP:
		rcr bl, 1
		rcl dl, 1
		LOOP REVERSEBITLOOP
		mov bl, dl
		pop ecx
		
		// (#C) nibble rotate left 1 
		mov dl, bl
		and bl, 0x0f  // bl now contains lower half of its original bits
		and dl, 0xf0  // dl now contains upper half of bl's original bits
		// rotate upper nibble left 1
		rcl dl, 1
		lahf
		rol dl, 3
		sahf
		rcl dl, 1
		shl dl, 4
		and dl, 0xF0
		// rotate lower nibble left 1
		shl bl, 4 
		rcl bl, 1
		lahf
		rol bl, 3
		sahf
		rcl bl, 1
		and bl, 0x0F
		// combine nibbles back into bl byte
		or bl, dl 
		
		// (#A) code table swap
		
		mov al, bl
		xor ebx, ebx
		mov bl, al
		lea eax, gEncodeTable
		add eax, ebx
		mov eax, [eax]
		mov bl, al
		
		
		mov [esi], bl // data[x] = data[x] ^ gKey[index];

		// loop stuff
		inc ecx
		mov edx, [ebp + 12] // set edx to dataLength
		cmp ecx, edx
		jne LOOP1
	}

	return;
} // encryptData_01

//////////////////////////////////////////////////////////////////////////////////////////////////
// EXAMPLE code to to show how to access global variables
int encryptData(char *data, int dataLength)
{
	int resulti = 0;

	gdebug1 = 0;				// a couple of global variables that could be used for debugging
	gdebug2 = 0;				// also can have a breakpoint in C code

	// You can not declare any local variables in C, but should use resulti to indicate any errors
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

		mov al,byte ptr [esi]				// get first byte of password hash
		mov al,byte ptr [esi+4]				// get 5th byte of password hash
		mov ebx,2
		mov al,byte ptr [esi+ebx]			// get 3rd byte of password hash
		mov al,byte ptr [esi+ebx*2]			// get 5th byte of password hash

		mov ax,word ptr [esi+ebx*2]			// gets 5th and 6th bytes of password hash ( gPasswordHash[4] and gPasswordHash[5] ) into ax
		mov eax,dword ptr [esi+ebx*2]		// gets 4 bytes, as in:  unsigned int X = *( (unsigned int*) &gPasswordHash[4] );

		mov al,byte ptr [gkey+ebx]			// get's 3rd byte of gkey[] data

		mov al,byte ptr [gptrKey+ebx]		// THIS IS INCORRECT - will add the address of the gptrKey global variable (NOT the value that gptrKey holds)

		mov al,byte ptr [esi+0xd];			// access 14th byte in gkey[]: 0, 1, 2 ... d is the 14th byte
		mov edi,data				// Put ADDRESS of first data element into edi
		xor byte ptr [edi+1],al		// Exclusive-or the 2nd byte of data with the 14th element of the keyfile
									// NOTE: Keyfile[14] = 0x21, that value changes the case of a letter and flips the LSB
									// Capital "B" = 0x42 becomes lowercase "c" since 0x42 xor 0x21 = 0x63
	}

	return resulti;
} // encryptData

