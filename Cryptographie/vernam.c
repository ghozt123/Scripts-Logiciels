//DEVELOPED by wil.tor
// Pas terminer !

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 50

typedef char* STRING;


void read_conditions();
void welcome_message();
void encrypt_text();
void decrypt_text();
void decrypt_text()
{
	welcome_message();

	char pDecryptCipherTextTextBuffer[BUFF_SIZE+1];
	char pDecryptCipherTextKeyBuffer[BUFF_SIZE+1];

	puts("Cipher text : \n");
	fgets(pDecryptCipherTextTextBuffer,sizeof(pDecryptCipherTextTextBuffer),stdin);
	puts("\nKey : \n");
	fgets(pDecryptCipherTextKeyBuffer,sizeof(pDecryptCipherTextKeyBuffer),stdin);
	int pCipherTextLen = strlen(pDecryptCipherTextTextBuffer);
	int pCipherKeyLen = strlen(pDecryptCipherTextKeyBuffer);
	size_t k;

	if(pCipherKeyLen < pCipherTextLen)
	{
		puts("\nRappel : La cle doit etre une suite de caractere au moins aussi longue que le texte.\n");
		exit(1);
	}
}

void encrypt_text()
{
	welcome_message();

	char *pEncryptClearTextTextBuffer = (char*)malloc(sizeof(BUFF_SIZE)*1);
	char *pEncryptClearTextKeyBuffer = (char*)malloc(sizeof(BUFF_SIZE)*1);
	char *pEncryptText = (char*)malloc(sizeof(BUFF_SIZE)*1);
	
	puts("Clear text : \n");
	fgets(pEncryptClearTextTextBuffer,sizeof(pEncryptClearTextTextBuffer),stdin);
	puts("\nKey : \n");
	fgets(pEncryptClearTextKeyBuffer,sizeof(pEncryptClearTextKeyBuffer),stdin);
	int pClearTextLen = strlen(pEncryptClearTextTextBuffer);
	int pClearKeyLen = strlen(pEncryptClearTextKeyBuffer);
	size_t i;

	if(pClearKeyLen < pClearTextLen)
	{
		puts("\nRappel : La cle doit etre une suite de caractere au moins aussi longue que le texte.\n");
		exit(1);
	}

	for(i=0;i!=pClearTextLen;i++)
	{
		pEncryptText += pEncryptClearTextTextBuffer[i] ^ pEncryptClearTextKeyBuffer[i];
	}

	printf("Cipher text : \n%s",pEncryptText);
}

void read_conditions()
{
	welcome_message();
	puts("Pour qu'un chiffrement de type masque jetable fonctionne, il faut compte quelques conditions tres particulieres : \n");
	puts("- La cle doit etre une suite de caracteres au moins aussi longue que le message.\n");
	puts("- La cle doit etre aleatoire.\n");
	puts("- Chaque cle/masque ne peut-etre utilise qu'une seule fois.\n");
	puts("\n\n[~] Si ces conditions sont respectes, le ciphertext est techniquement inviolable.\n");
}

void welcome_message()
{
	system("clear");
	puts("~~~~~~~~~~ Vernam-Chiffrement ~~~~~~~~~~~\n");
	puts("              by wil.tor\n");
}

int main()
{
	char *buf = (char*) malloc(sizeof(char)*1);

	welcome_message();
	puts("\n[1] - Chiffrer\n");
	puts("[2] - Déchiffrer\n");
	puts("[3] - Conditions\n");

	fgets(buf,sizeof(buf),stdin);

	switch(*buf)
	{
		case'1':
			encrypt_text();
			break;
		case'2':
			decrypt_text();
			break;
		case'3':
			read_conditions();
			break;
		default:
			puts("1 ou 2 ou 3\n");
			exit(1);
	}

	free(buf);
	return 0;
}
