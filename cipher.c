// Project: 	Caesar Ciphers
// Author:	Yonglei Tao

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

/**
	Encrypts a character using the Caesar cipher.
	@param ch the character to encrypt
	@param k the encryption key
	@return the encrypted character
*/
char encrypt(char ch, int k)
{
	if ( k < 0 )
		k = k + 26;

	if ( isupper(ch) )
		return (ch - 'A' + k) % 26 + 'A';
	
	if ( islower(ch) )
		return (ch - 'a' + k) % 26 + 'a';
	
	return ch;
}

void calcFreq()
{
    int frequency[26];
    int ch;
    File* given = fopen ("given.txt", "rt");

    // init frequency
    for (ch = 0; ch < 26; ch++)
        frequency[ch] = 0;

    while (1)
    {
        ch = fgetc(given);
        if (ch == EOF) break;

        if ('a' <=ch && ch <= 'z')
            frequency[ch - 'a']++;
        else if ('A' <= ch && ch <= 'Z')
            frequency[ch - 'A']++;
    }
}

int main(int argc, char* argv[])
{  
	int choice, key;
	char ch;
	FILE *fin, *fout;

	if (argc != 5)
	{
		printf ("Usage: cipher option key infile, outfile\n");
		printf ("Option 1 for encryption and 2 for decryption");
		exit(1);
	}
	
	choice = atoi(argv[1]);
	key = atoi(argv[2]);

	if (choice == 2)
		key = -key;
	
    	fin = fopen(argv[3], "r");
	fout = fopen(argv[4], "w");
    
    	if (fin ==  NULL || fout == NULL) 
	{
		printf("File could not be opened\n");
		exit(1);
	}

	while ( fscanf(fin, "%c", &ch) != EOF )
	{
		fprintf(fout, "%c", encrypt(ch, key));
	}

	fclose(fin);
	fclose(fout);

	return 0;
}
