// DEVELOPED by ghozt123

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_SIZE 250


void      __hex_to_ascii();
void      __ascii_to_hex();
void      __ascii_to_hex()
{
	system("clear");

	char ascii_to_hex_input[INPUT_SIZE+1];
	int ascii_to_hex_input_len;
	int i; 
	puts("Input : \n");
	scanf("%s",ascii_to_hex_input);
	ascii_to_hex_input_len = strlen(ascii_to_hex_input);

	for(i=0;i<ascii_to_hex_input_len;i++)
	{
		printf("\nHex : %x",ascii_to_hex_input[i]);
	}
	
}

void      __hex_to_ascii()
{
	system("clear");

	char hex_to_ascii_input[INPUT_SIZE+1];
	int hex_to_ascii_input_len;
	int k;

	puts("Input : \n");
	scanf("%x",hex_to_ascii_input);
	hex_to_ascii_input_len = strlen(hex_to_ascii_input);

	for(k=0;k<hex_to_ascii_input_len;k++)
	{
		printf("\nAscii : %c\n",hex_to_ascii_input[k]);
	}
}

int main()
{
	char * input = (char *) malloc(sizeof(char)*1);

	system("clear");

	puts("~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	puts("~~~ASCII-HEX CONVERTER~~~\n");
	puts("~~~~~~~~~~~~~~~~~~~~~~~~~\n");

	puts("\nOPTIONS: \n");
	puts("HEX-->ASCII\n");
	puts("ASCII-->HEX\n");
	puts("1 or 2 : \n");
	scanf("%s",input);

	switch(*input)
	{
		case'1':
			__hex_to_ascii();
			break;
		case'2':
			__ascii_to_hex();
			break;
		default:
			puts("Format : 1or2");
			exit(1);
			break;
	}
	return 0;
}
