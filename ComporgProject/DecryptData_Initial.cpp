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
		mov	dword ptr[ebp - 4], 0x0000 // round
		xor ebx, ebx
		mov	bh, gPasswordHash[0] // gPasswordHash[0+round*4] * 256
		mov	bl, gPasswordHash[1] // gPasswordHash[1+round*4]
		mov dword ptr[ebp - 8], 0x0000 // clearing all 4 bytes of memory
		mov	dword ptr[ebp - 8], ebx // storing index  at ebp - 8

		mov	ah, gPasswordHash[2]
		mov	al, gPasswordHash[3]
		cmp ax, 0x0
		JNE NO_FFFF
		mov ax, 0xFFFF
		NO_FFFF:
		mov dword ptr[ebp - 12], 0x0000
		mov	word ptr[ebp - 12], ax // hop_count

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

		mov eax, [ebp - 8]
		add eax, [ebp - 12]
		cmp eax, 65537d
		JL NO_RESET
		sub eax, 65537d
		NO_RESET :
		mov[ebp - 8], eax

		// loop stuff
		inc ecx
		mov edx, [ebp + 12] // set edx to dataLength
		cmp ecx, edx
		jne LOOP1
	}

	return;
} // decryptData_01

