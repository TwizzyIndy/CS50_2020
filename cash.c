#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main()
{
    float fUserInput = 0.00;
    do{
         fUserInput = get_float("Change owned : ");

    } while ( fUserInput < 0.00 );

    int nQuarter = 25;
    int nDime = 10;
    int nNickel = 5;
    int nPennies = 1;

    int nOutputCoins = 0;

    int nUserInput = round(fUserInput * 100);

    if( nUserInput != 0 )
    {
        int x = nUserInput / nQuarter;
        int y = (nUserInput % 25) / nDime;
        int z = (nUserInput % 25 % 10) / nNickel;
        int k = (nUserInput % 5) / nPennies;

        nOutputCoins = x + y + z + k;
        printf("%i\n", nOutputCoins);
    }

    return 0;
}
