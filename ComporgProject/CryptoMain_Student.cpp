// Main.cpp
//

#include "Main.h"

// Global Encode/Decode Tables
#if CURRENT_SEMESTER == FALL_2020
unsigned char gDecodeTable[256] = {
#else
unsigned char gEncodeTable[256] = {
#endif
	0x27, 0x46, 0x17, 0x07,	 0x3C, 0xFF, 0x3F, 0xD3,  	0x4C, 0xB2, 0xC1, 0xC3,	 0x5F, 0x15, 0x04, 0xEF,
	0x38, 0xAE, 0x0E, 0x97,	 0x2D, 0x4D, 0xF8, 0xC2,  	0x35, 0xDA, 0x9F, 0x24,	 0x43, 0x50, 0x9D, 0x45,
	0xD2, 0x0A, 0x78, 0xE0,	 0x3E, 0x18, 0x89, 0x62,  	0xC7, 0x7F, 0x93, 0xCE,	 0xB4, 0x31, 0x7B, 0xCC,
	0x00, 0xDB, 0x10, 0x92,	 0x5D, 0xF4, 0x77, 0x8A,  	0x2C, 0xA9, 0x34, 0xFA,	 0x26, 0x1C, 0xF6, 0xA4,
	0x95, 0x6C, 0x4B, 0xC4,	 0x09, 0x5A, 0x74, 0xEC,  	0x6A, 0xAF, 0x4A, 0x84,	 0x63, 0x0D, 0xAA, 0x14,
	0x30, 0x16, 0x64, 0x6D,	 0x58, 0xD0, 0xBB, 0xD8,  	0x75, 0xE5, 0x2A, 0x9B,	 0x41, 0xC8, 0x8D, 0xE6,
	0x01, 0xB1, 0xA0, 0xF3,	 0xEB, 0x9E, 0x69, 0x87,  	0x37, 0x81, 0x48, 0x7C,	 0xA8, 0xC0, 0xF5, 0xB7,
	0x23, 0xA3, 0x7E, 0x2E,	 0xE4, 0x1D, 0x56, 0x33,  	0x3D, 0xA5, 0xE3, 0xD1,	 0xBF, 0x55, 0x22, 0xC6,

	0xC9, 0xDF, 0x32, 0x9C,	 0xFD, 0xD6, 0x03, 0x06,  	0x5C, 0x8E, 0xB0, 0x3B,	 0x8C, 0x36, 0x4F, 0x02,
	0x25, 0x7A, 0xED, 0x7D,	 0xD5, 0x82, 0x11, 0x90,  	0x0B, 0xCD, 0xB3, 0xAB,	 0x2B, 0x53, 0xB6, 0x54,
	0xA2, 0xE8, 0x59, 0x72,	 0x86, 0x83, 0xCA, 0x49,  	0x6E, 0x40, 0xBC, 0x61,	 0x52, 0xFE, 0x79, 0xEA,
	0x29, 0x42, 0x88, 0x96,	 0xBE, 0x12, 0xCB, 0xBA,  	0x08, 0x1E, 0x51, 0x2F,	 0x44, 0x20, 0x65, 0x6B,
	0x4E, 0x67, 0xEE, 0xA6,	 0x71, 0xDC, 0x76, 0x19,  	0xDE, 0xF2, 0xFB, 0x70,	 0x21, 0xCF, 0x73, 0x68,
	0xE7, 0xB9, 0xF1, 0x5B,	 0x91, 0xD9, 0xD4, 0x99,  	0x1B, 0xE1, 0xF0, 0xDD,	 0xFC, 0xE2, 0x39, 0x5E,
	0x1A, 0x66, 0x60, 0xA7,	 0x8B, 0xB8, 0xD7, 0x94,  	0xE9, 0xAC, 0xC5, 0x9A,	 0xBD, 0x6F, 0xF9, 0x28,
	0x13, 0x05, 0x57, 0xB5,	 0x0C, 0x80, 0x8F, 0x3A,  	0x1F, 0x47, 0x98, 0x0F,	 0xF7, 0xAD, 0x85, 0xA1
};

#if CURRENT_SEMESTER == FALL_2020
	unsigned char gEncodeTable[256] = {
#else
	unsigned char gDecodeTable[256] = {
#endif
	0x30, 0x60, 0x8F, 0x86,	 0x0E, 0xF1, 0x87, 0x03,  	0xB8, 0x44, 0x21, 0x98,	 0xF4, 0x4D, 0x12, 0xFB,
	0x32, 0x96, 0xB5, 0xF0,	 0x4F, 0x0D, 0x51, 0x02,  	0x25, 0xC7, 0xE0, 0xD8,	 0x3D, 0x75, 0xB9, 0xF8,
	0xBD, 0xCC, 0x7E, 0x70,	 0x1B, 0x90, 0x3C, 0x00,  	0xEF, 0xB0, 0x5A, 0x9C,	 0x38, 0x14, 0x73, 0xBB,
	0x50, 0x2D, 0x82, 0x77,	 0x3A, 0x18, 0x8D, 0x68,  	0x10, 0xDE, 0xF7, 0x8B,	 0x04, 0x78, 0x24, 0x06,
	0xA9, 0x5C, 0xB1, 0x1C,	 0xBC, 0x1F, 0x01, 0xF9,  	0x6A, 0xA7, 0x4A, 0x42,	 0x08, 0x15, 0xC0, 0x8E,
	0x1D, 0xBA, 0xAC, 0x9D,	 0x9F, 0x7D, 0x76, 0xF2,  	0x54, 0xA2, 0x45, 0xD3,	 0x88, 0x34, 0xDF, 0x0C,
	0xE2, 0xAB, 0x27, 0x4C,	 0x52, 0xBE, 0xE1, 0xC1,  	0xCF, 0x66, 0x48, 0xBF,	 0x41, 0x53, 0xA8, 0xED,
	0xCB, 0xC4, 0xA3, 0xCE,	 0x46, 0x58, 0xC6, 0x36,  	0x22, 0xAE, 0x91, 0x2E,	 0x6B, 0x93, 0x72, 0x29,

	0xF5, 0x69, 0x95, 0xA5,	 0x4B, 0xFE, 0xA4, 0x67,  	0xB2, 0x26, 0x37, 0xE4,	 0x8C, 0x5E, 0x89, 0xF6,
	0x97, 0xD4, 0x33, 0x2A,	 0xE7, 0x40, 0xB3, 0x13,  	0xFA, 0xD7, 0xEB, 0x5B,	 0x83, 0x1E, 0x65, 0x1A,
	0x62, 0xFF, 0xA0, 0x71,	 0x3F, 0x79, 0xC3, 0xE3,  	0x6C, 0x39, 0x4E, 0x9B,	 0xE9, 0xFD, 0x11, 0x49,
	0x8A, 0x61, 0x09, 0x9A,	 0x2C, 0xF3, 0x9E, 0x6F,  	0xE5, 0xD1, 0xB7, 0x56,	 0xAA, 0xEC, 0xB4, 0x7C,
	0x6D, 0x0A, 0x17, 0x0B,	 0x43, 0xEA, 0x7F, 0x28,  	0x5D, 0x80, 0xA6, 0xB6,	 0x2F, 0x99, 0x2B, 0xCD,
	0x55, 0x7B, 0x20, 0x07,	 0xD6, 0x94, 0x85, 0xE6,  	0x57, 0xD5, 0x19, 0x31,	 0xC5, 0xDB, 0xC8, 0x81,
	0x23, 0xD9, 0xDD, 0x7A,	 0x74, 0x59, 0x5F, 0xD0,  	0xA1, 0xE8, 0xAF, 0x64,	 0x47, 0x92, 0xC2, 0x0F,
	0xDA, 0xD2, 0xC9, 0x63,	 0x35, 0x6E, 0x3E, 0xFC,  	0x16, 0xEE, 0x3B, 0xCA,	 0xDC, 0x84, 0xAD, 0x05
};


// Global Variables
unsigned char gkey[65537];
unsigned char *gptrKey = gkey;			// used for inline assembly routines, need to access this way for Visual Studio
char gPassword[256] = "SECRET";
unsigned char gPasswordHash[32];
unsigned char *gptrPasswordHash = gPasswordHash;	// used for inline assembly routines, need to access this way for Visual Studio
char gCRYPTO_ORDER[8] = CRYPTO_ORDER;
unsigned char gdebug1, gdebug2;

FILE *gfptrIn = NULL;
FILE *gfptrOut = NULL;
FILE *gfptrKey = NULL;
char gInFileName[256];
char gOutFileName[256];
char gKeyFileName[256];
int gOp = 0;			// 1 = encrypt, 2 = decrypt
int gNumRounds = 1;
int gMilestone = 1;


// code to read the file to encrypt
int encryptFile(FILE *fptrIn, FILE *fptrOut)
{
	char *buffer;
	unsigned int filesize;

	fseek(fptrIn, 0, SEEK_END);
	filesize = ftell(fptrIn);
	fseek(fptrIn, 0, SEEK_SET);

	if(filesize > 0x1000000)					// 16 MB, file too large
	{
		fprintf(stderr, "Error - Input file to encrypt is too large.\n\n");
		return -1;
	}

	// use the password hash to encrypt
	buffer = (char *) malloc(filesize);
	if(buffer == NULL)
	{
		fprintf(stderr, "Error - Could not allocate %d bytes of memory on the heap.\n\n", filesize);
		return -1;
	}

	fread(buffer, 1, filesize, fptrIn);	// read entire file

	switch(gMilestone)
	{
	case 1:
		encryptData_01(buffer, filesize);
		break;

	case 2:
//		encryptData_02(buffer, filesize);
		break;

	case 3:
//		encryptData_03(buffer, filesize);
		break;
	}

	fwrite(buffer, 1, filesize, fptrOut);
	free(buffer);

	return 0;
} // encryptFile


// code to read in file and prepare for decryption
int decryptFile(FILE *fptrIn, FILE *fptrOut)
{
	char *buffer;
	unsigned int filesize;

	fseek(fptrIn, 0, SEEK_END);
	filesize = ftell(fptrIn);
	fseek(fptrIn, 0, SEEK_SET);

	if(filesize > 0x1000000)					// 16 MB, file too large
	{
		fprintf(stderr, "Error - Input file to decrypt is too large.\n\n");
		return -1;
	}

	// use the password hash to encrypt
	buffer = (char *) malloc(filesize);
	if(buffer == NULL)
	{
		fprintf(stderr, "Error - Could not allocate %d bytes of memory on the heap.\n\n", filesize);
		return -1;
	}

	fread(buffer, 1, filesize, fptrIn);	// read entire file

	switch(gMilestone)
	{
	case 1:
		decryptData_01(buffer, filesize);
		break;

	case 2:
//		decryptData_02(buffer, filesize);
		break;

	case 3:
//		decryptData_03(buffer, filesize);
		break;
	}

	fwrite(buffer, 1, filesize, fptrOut);
	free(buffer);

	return 0;
} // decryptFile

//////////////////////////////////////////////////////////////////////////////////////////////////
FILE *openInputFile(char *filename)
{
	FILE *fptr;
	long sz;

	fptr = fopen(filename, "rb");
	if(fptr == NULL)
	{
		fprintf(stderr, "\n\nError - Could not open input file %s!\n\n", filename);
		exit(-1);
	}

	fseek(fptr, 0, SEEK_END);
	sz = ftell(fptr);
	fseek(fptr, 0, SEEK_SET);

	if(sz == 0)
	{
		fprintf(stderr, "Error - File size is zero for \"%s\".\n\n", filename);
		fprintf(stderr, "Aborting operation - try again!\n\n");
		fclose(fptr);
		exit(0);
	}

	return fptr;
} // openInputFile

FILE *openOutputFile(char *filename)
{
	FILE *fptr;

	fptr = fopen(filename, "wb+");
	if(fptr == NULL)
	{
		fprintf(stderr, "\n\nError - Could not open output file %s!\n\n", filename);
		exit(-1);
	}
	return fptr;
} // openOutputFile


void usage(char *argv[])	//   cryptor.exe -e -i <input file> �k <keyfile> -p <password> [�r <#rounds>]
{
	printf("\n\nUsage:\n\n");

	printf("To Encrypt:\n");
	printf("%s -e <message_filename> -k <keyfile> -p <password> [-r <#rounds> -x <crypto order>]\n\n", argv[0]);

	printf("To Decrypt:\n");
	printf("%s -d <message_filename> -k <keyfile> -p <password> [-r <#rounds> -x <crypto order>]\n\n", argv[0]);

	printf("-e filename		:encrypt the specified file\n");
	printf("-d filename		:decrypt the specified file\n");
	printf("-p password		:the password to be used for encryption [default='password']\n");
	printf("-r <#rounds>		:number of encryption rounds (1 - 3)  [default = 1]\n");
	printf("-x crypto order		: [default=ABCDE] \n");
	printf("-m <milestone #>	: [default=4]\n\n");
	printf("-o filename		:name of the output file [default='encrypted.txt' or 'decrypted.txt'\n\n");
	printf("The order of the options is irrelevant.\n\n");

	system("pause");

	exit(0);
} // usage

void parseCommandLine(int argc, char *argv[])
{
	int cnt, tmpi;
	char ch;
	bool i_flag, o_flag, k_flag, p_flag, err_flag;

	i_flag = k_flag = false;				// these must be true in order to exit this function
	err_flag = p_flag = o_flag = false;		// these will generate different actions

	cnt = 1;	// skip program name
	while(cnt < argc)
	{
		ch = *argv[cnt];
		if(ch != '-')
		{
			fprintf(stderr, "All options must be preceeded by a dash '-', argv[%d]=%s\n\n", cnt, argv[cnt]);
			usage(argv);
		}

		ch = *(argv[cnt]+1);
		if(0)
		{
		}

		else if(ch == 'e' || ch == 'E')		// encrypt
		{
			if(i_flag == true || gOp != 0)
			{
				fprintf(stderr, "Error! Already specifed an input file - can't encrypt/decrypt multiple files.\n\n");
				usage(argv);
			}

			i_flag = true;
			cnt++;
			if(cnt >= argc)
			{
				fprintf(stderr, "Error! Must specify a filename after '-e'\n\n");
				usage(argv);
			}

			strncpy(gInFileName, argv[cnt], 256);
			gOp = 1;	// encrypt
		}

		else if(ch == 'd' || ch == 'D')		// decrypt
		{
			if(i_flag == true || gOp != 0)
			{
				fprintf(stderr, "Error! Already specifed an input file - can't decrypt/encrypt multiple files.\n\n");
				usage(argv);
			}

			i_flag = true;
			cnt++;
			if(cnt >= argc)
			{
				fprintf(stderr, "Error! Must specify a filename after '-d'\n\n");
				usage(argv);
			}

			strncpy(gInFileName, argv[cnt], 256);
			gOp = 2;	// decrypt
		}

		else if(ch == 'o' || ch == 'O')		// output file name
		{
			if(o_flag == true)
			{
				fprintf(stderr, "Error! Already specifed an output file.\n\n");
				usage(argv);
			}
			o_flag = true;
			cnt++;
			if(cnt >= argc)
			{
				fprintf(stderr, "Error! Must specify a filename after '-o'\n\n");
				usage(argv);
			}
			strncpy(gOutFileName, argv[cnt], 256);
		}

		else if(ch == 'k' || ch == 'K')		// key file
		{
			if(k_flag == true)
			{
				fprintf(stderr, "Error! Already specifed a key file.\n\n");
				usage(argv);
			}
			k_flag = true;
			cnt++;
			if(cnt >= argc)
			{
				fprintf(stderr, "Error! Must specify a filename after '-k'\n\n");
				usage(argv);
			}
			strncpy(gKeyFileName, argv[cnt], 256);
		}

		else if(ch == 'p' || ch == 'P')		// password
		{
			if(p_flag == true)
			{
				fprintf(stderr, "Error! Already specifed a password.\n\n");
				usage(argv);
			}
			p_flag = true;
			cnt++;
			if(cnt >= argc)
			{
				fprintf(stderr, "Error! Must enter a password after '-p'\n\n");
				usage(argv);
			}
			strncpy(gPassword, argv[cnt], 256);
		}

		else if(ch == 'r' || ch == 'R')		// # rounds
		{
			int x;

			cnt++;
			if(cnt >= argc)
			{
				fprintf(stderr, "Error! Must enter number between 1 and 3 after '-r'\n\n");
				usage(argv);
			}
			x = atoi(argv[cnt]);
			if(x < 1 || x > 3)
			{
				fprintf(stderr, "Warning! Entered bad value for number of rounds. Setting it to one.\n\n");
				x = 1;
			}
			gNumRounds = x;
		}

		else if(ch == 'x' || ch == 'X')		// crypto order specified
		{
			cnt++;
			if(cnt >= argc)
			{
				fprintf(stderr, "Error! Must 5 letter crypto order\n\n");
				usage(argv);
			}

			strncpy(gCRYPTO_ORDER, argv[cnt], 5);
		}

		else if(ch == 'm' || ch == 'M')		// which milestone to use
		{
			cnt++;
			if(cnt >= argc)
			{
				fprintf(stderr, "Error! Must enter the milestone number for the encryption (1 - 4, 4 being final)\n\n");
				usage(argv);
			}

			tmpi = atoi(argv[cnt]);
			if(tmpi < 1 || tmpi > 4)
			{
				fprintf(stderr, "Error! Must enter a milestone number between 1 and 4.\n\n");
				usage(argv);
			}
			gMilestone = tmpi;
		}

		else
		{
			fprintf(stderr, "Error! Illegal option in argument. %s\n\n", argv[cnt]);
			usage(argv);
		}

		cnt++;
	} // end while

	if(gOp == 0)
	{
		fprintf(stderr, "Error! Encrypt or Decrypt must be specified.\n\n)");
		err_flag = true;
	}

	if(i_flag == false)
	{
		fprintf(stderr, "Error! No input file specified.\n\n");
		err_flag = true;
	}

	if(k_flag == false)
	{
		fprintf(stderr, "Error! No key file specified.\n\n");
		err_flag = true;
	}

	if(p_flag == false)
	{
		fprintf(stderr, "Warning! Using default 'password'.\n\n");
	}

	if(o_flag == false && err_flag == false)	// no need to do this if we have errors
	{
		strcpy(gOutFileName, gInFileName);
		if(gOp == 1)	// encrypt
		{
			strcat(gOutFileName, ".enc");
		}
		if(gOp == 2)	// decrypt
		{
			strcat(gOutFileName, ".dec");
		}
	}

	if(err_flag)
	{
		usage(argv);
	}
	return;
} // parseCommandLine

// makes sure all caps and that sequence has valid letters
void checkCryptoOrder()
{
	int i;

	if(strlen(gCRYPTO_ORDER) != 5)
	{
		fprintf(stderr, "Warning - Crypto Order has a non-standard length!\n\n");
	}

	for(i = 0; i < (int) strlen(gCRYPTO_ORDER); i++)
	{
		if(gCRYPTO_ORDER[i] < 'A' || gCRYPTO_ORDER[i] > 'E')
		{
			fprintf(stderr, "Error - Crypto Order <%s> has invalid characters. Must be caps between 'A' and 'E'\n\n", gCRYPTO_ORDER );
			exit(0);
		}
	}
	return;
} // checkCryptoOrder

// main program for CS3844 Semester Project
int main(int argc, char *argv[])
{
	int length, resulti;

	printf("\n\n");
	// parse command line parameters
	parseCommandLine(argc, argv);		// sets global variables, checks input options for errors

	checkCryptoOrder();

	// open the input and output files
	gfptrIn = openInputFile(gInFileName);
	gfptrKey = openInputFile(gKeyFileName);
	gfptrOut = openOutputFile(gOutFileName);

	strcat(gPassword, gCRYPTO_ORDER);
	length = (size_t) strlen(gPassword);
	resulti = sha256(NULL, gPassword, length, gPasswordHash);		// get sha-256 hash of password
	if(resulti != 0)
	{
		fprintf(stderr, "Error! Password not hashed correctly.\n\n");
		exit(-1);
	}

	length = fread(gkey, 1, 65537, gfptrKey);
	if(length != 65537)
	{
		fprintf(stderr, "Error! Length of key file is not at least 65537.\n\n");
		exit(-1);
	}
	fclose(gfptrKey);
	gfptrKey = NULL;

	if(gOp == 1)	// encrypt
	{
		fprintf(stdout, "\n\nEncrypt Crypto Order:%s\n\n", gCRYPTO_ORDER);
		encryptFile(gfptrIn, gfptrOut);
	}
	else
	{
		fprintf(stdout, "\n\nDecrypt Crypto Order:%s\n\n", gCRYPTO_ORDER);
		decryptFile(gfptrIn, gfptrOut);
	}

	fclose(gfptrIn);
	fclose(gfptrOut);

system("pause");

	return 0;
} // main
