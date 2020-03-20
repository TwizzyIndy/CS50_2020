#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


void print_usage()
{
    printf("Usage: ./substitution key\n");
}

int find_index_in_abc(char strInput)
{
    // odinary chars
    char* strABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char* strLowerABC = "abcdefghijklmnopqrstuvwxyz";

    int result = 0;

    for(int i=0; i < strlen(strABC); i++)
    {
        if(strInput == strABC[i] || strInput == strLowerABC[i] ) // found, and return its index
        {
            result = i;
        }
    }

    return result;
}

int main(int argc, char** argv)
{

    if(argc != 2)
    {
        print_usage();
        return 1;
    }

    char* key = argv[1];

    // len check
    if(strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }


    // parse key by word by word
    int count = 0;

    for(int p=0; p < strlen(key); p++)
    {
        if(isalpha(key[p]) == 0)
        {
            print_usage();
            return 1;
        } else
        {
            // find duplicate
            count = 1;
            for(int j = p+1; j < strlen(key); j++)
            {
               if(key[p] == key[j] && key[p] != ' ')
               {
                  count++;
                  //Set key[j] to 0 to avoid printing visited character
                  key[j] = '0';
               }
            }
            //A character is considered as duplicate if count is greater than 1
            if(count > 1 && key[p] != '0')
            {
               printf("Key must not contain repeated characters.\n");
               return 1;
            }


        }
    }

    // get plaintext
    string strPlainText = get_string("plaintext: ");

    char strCipher[256];
    memset(strCipher, 0x00, 255);

    // parse plain text
    for(int i=0; i < strlen(strPlainText); i++)
    {
        if( isalpha(strPlainText[i]) != 0)
        {
            // key : YTNSHKVEFXRBAUQZCLWDMIPGJO
            // plaintext:  HELLO
            // ciphertext: EHBBQ
            //
            // plaintext:   ABCDEF
            // cipher :     YTNSHK

            int nGetOriginalIndex = find_index_in_abc(strPlainText[i]);

            strCipher[i] = key[nGetOriginalIndex];

            // if lower or upper, change it
            if (islower(strPlainText[i]) != 0)
                strCipher[i] = tolower(strCipher[i]);

            if(isupper(strPlainText[i]) != 0 )
                strCipher[i] = toupper(strCipher[i]);


        } else {
            strCipher[i] = strPlainText[i];
        }
    }

    printf("ciphertext: %s\n", strCipher);

    return 0;
}
