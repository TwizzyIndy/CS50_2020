#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void print_usage()
{
    printf("Usage: ./caesar key\n");
}

char encrypt(char plainChar, char startChar, int shift)
{
    return (startChar + (shift + plainChar - startChar) % 26);
}

int main(int argc, char** argv)
{
    if(argc != 2)
    {
        print_usage();
        return 1;
    }

    char* s = argv[1];

    // parse isdigit
    for(int k=0; k < strlen(s); k++ )
    {
        if(isdigit(s[k]) == 0)
        {
            print_usage();
            return 1;
        }
    }

    int k = atoi(argv[1]);

    if( k < 0 )
    {
        printf("Key must be a non-negative integer.\n");
        return 1;
    }

    string strPlainText = get_string("plaintext: ");

    char strCipher[50];
    memset(strCipher, 0x00, 50);
    strcpy(strCipher, strPlainText);

    // parse

    for(int i=0; i < strlen(strPlainText); i++)
    {

        if( (strPlainText[i] >= 'a' && strPlainText[i] <= 'z') || (strPlainText[i] >= 'A' && strPlainText[i] <= 'Z') )
        {

            // its nested if i know
            if(strPlainText[i] >= 'A' && strPlainText[i] <= 'Z')
            {

                //if(strCipher[i] > 'Z')
                //{
                    //strCipher[i] = '@' + (strCipher[i] - 'Z'); // @ is 64th char of ASCII table which is in front of A
                    strCipher[i] = encrypt(strPlainText[i], 'A', k);
                //} else
                //{
                    //strCipher[i] = strCipher[i];
                //}
            }

            if(strPlainText[i] >= 'a' && strPlainText[i] <= 'z')
            {
                strCipher[i] = encrypt(strPlainText[i], 'a', k);
            }
        }
        // if sperators or symbols and spaces found
        else if (strPlainText[i] == ' ' || strPlainText[i] == '.' || strPlainText[i] == ',' || strPlainText[i] == '\'' || strPlainText[i] == '\"')
        {
            strCipher[i] = strPlainText[i];

        } else
        {
            print_usage();
            break;
        }
    }

    printf("ciphertext: %s\n", strCipher);

    return 0;
}
