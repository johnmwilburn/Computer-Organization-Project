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
		mov	dword ptr[ebp - 4], 0x0000 // round
		mov	ah, gPasswordHash[0] // gPasswordHash[0+round*4] * 256
		mov	al, gPasswordHash[1] // gPasswordHash[1+round*4]
		mov dword ptr [ebp - 8], 0x0000
		mov	word ptr [ebp - 8], ax // storing index at ebp - 8

		mov	ah, gPasswordHash[2]
		mov	al, gPasswordHash[3]
		cmp ax, 0x0000
		JNE NO_FFFF
		mov ax, 0xFFFF
		NO_FFFF:
		mov dword ptr[ebp - 12], 0x0000
		mov	word ptr[ebp - 12], ax // hop_count

		xor ecx, ecx
		
		LOOP1:
		mov esi, [ebp + 8] // preserving data address
		add esi, ecx // add x to data to get data[x]
		mov eax, [esi] // copy data[x] address to eax for use in xor
		
		lea ebx, gkey // set ebx to address gkey
		add ebx, [ebp - 8]  // gkey[index]
		nop
		mov ebx, [ebx]
		
		xor bl, al // xor data[x] with gKey[index]

		mov eax, [ebp-8]
		add eax, [ebp-12]
		cmp eax, 65537d
		JL NO_RESET
		sub eax, 65537d
		NO_RESET:
		mov [ebp-8], eax
		

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
		mov eax, ebx
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

