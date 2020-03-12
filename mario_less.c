#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int nHeight = 0;
    int spaces = 0;
    int dashes = 0;
    
    do {
      
      nHeight = get_int("Height: ");

    } while (nHeight < 1 || nHeight > 8);

    for(int i = 0; i < nHeight; i++)
    {
        for(spaces = (nHeight-i); spaces > 1; spaces--)
        {
            printf(" ");
        }

        for(dashes = 1;dashes < (i+2);dashes++)
        {
            printf("#");
        }

        printf("\n");
    }
}
