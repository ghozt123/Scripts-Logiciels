/******************************************************************************************

  Copyright 2016-2017 William Bascle
   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.

******************************************************************************************/
// DEVELOPED by ghozt123

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void       __encrypt_cesar_hash_algorithm();
void       __decrypt_cesar_hash_algorithm();
void       __decrypt_cesar_hash_algorithm()
{
	char *decrypt_input_buffer = (char *)malloc(sizeof(char)*100);
	char decrypt_res;
  int k, decrypt_key;

		puts("\n-Texte à déchiffrer : ");
    fgets(decrypt_input_buffer,100,stdin);
    puts("-Décalage (en chiffre) : ");
    scanf("%d", &decrypt_key);

	   for(k = 0; decrypt_input_buffer[k] != '\0'; ++k){
        decrypt_res = decrypt_input_buffer[k];

        if(decrypt_res >= 'a' && decrypt_res <= 'z'){
            decrypt_res = decrypt_res - decrypt_key;

            if(decrypt_res < 'a'){
                decrypt_res = decrypt_res + 'z' - 'a' + 1;
            }

            decrypt_input_buffer[k] = decrypt_res;
        }
        else if(decrypt_res >= 'A' && decrypt_res <= 'Z'){
            decrypt_res = decrypt_res - decrypt_key;

            if(decrypt_res < 'A'){
                decrypt_res = decrypt_res + 'Z' - 'A' + 1;
            }

            decrypt_input_buffer[k] = decrypt_res;
        }
    }

    printf("-Message déchiffrer : %s", decrypt_input_buffer);
}

void       __encrypt_cesar_hash_algorithm()
{
	char *encrypt_input_buffer = (char *)malloc(sizeof(char)*100);
	char res;
  int i, key;

    puts("-Texte à chiffrer : ");
    fgets(encrypt_input_buffer,100,stdin);
    puts("-Décalage (en chiffre) : ");
    scanf("%d", &key);

    for(i = 0; encrypt_input_buffer[i] != '\0'; ++i){
        res = encrypt_input_buffer[i];

        if(res >= 'a' && res <= 'z'){
            res = res + key;

            if(res > 'z'){
                res = res - 'z' + 'a' - 1;
            }

            encrypt_input_buffer[i] = res;
        }
        else if(res >= 'A' && res <= 'Z'){
            res = res + key;

            if(res > 'Z'){
                res = res - 'Z' + 'A' - 1;
            }

            encrypt_input_buffer[i] = res;
        }
    }
		printf("-Texte déchiffrer : %s", encrypt_input_buffer);
}

int        main(int argc, char **argv)
{
	char *main_buffer = (char *)malloc(sizeof(char)*1);

	puts("\n -[1] Déchiffrer \n\n -[2] Chiffrer \n");
	fgets(main_buffer, sizeof(main_buffer), stdin);

	switch(*main_buffer)
	{
		case'2':
		__encrypt_cesar_hash_algorithm();
		break;
		case'1':
		__decrypt_cesar_hash_algorithm();
		break;
	}

	return 0;
}
