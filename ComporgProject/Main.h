// Main.h
//
// This file is the main header file for the CS3843 Encrypt/Decrypt project
//



// Include Files
#include <windows.h>
#include <stdio.h>
#include <io.h>

// Defines
#define _CRT_SECURE_NO_WARNINGS

// #define TEST_CODE
#define CRYPTO_ORDER "DEBCA\0"
#define var_Index -4
#define var_HopCnt -8
#define var_RoundNum -12
#define var_DataLength -16


#define FALL_2017		201708
#define SPRING_2018		201801
#define SUMMER_2018		201806
#define FALL_2018		201808
#define FALL_2022		202208

#define CURRENT_SEMESTER FALL_2022

// Structures


// Prototypes
int sha256(char *fileName, char *dataBuffer, DWORD dataLength, unsigned char sha256sum[32]);
void encryptData_01(char *data, int length);
void decryptData_01(char *data, int length);
void encryptData_02(char *data, int length);
void decryptData_02(char *data, int length);
void encryptData_03(char *data, int length);
void decryptData_03(char *data, int length);

int encryptData(char *data, int dataLength);
int decryptData(char *data, int dataLength);

// Global Variable Extern Declarations
extern unsigned char gkey[65537];
extern unsigned char *gptrKey;
extern char gPassword[256];
extern unsigned char gPasswordHash[32];
extern unsigned char *gptrPasswordHash;
extern char gCRYPTO_ORDER[8];
extern unsigned char gdebug1, gdebug2;

extern FILE *gfptrIn;
extern FILE *gfptrOut;
extern FILE *gfptrKey;
extern char gInFileName[256];
extern char gOutFileName[256];
extern char gKeyFileName[256];
extern int gOp;			// 1 = encrypt, 2 = decrypt
extern int gNumRounds;

extern unsigned char gEncodeTable[256];
extern unsigned char gDecodeTable[256];


