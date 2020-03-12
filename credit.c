#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


int check_number(char *number)
{
    int i, sum, ch, num, twoup, len;

    len = (int) strlen(number);
    sum = 0;
    twoup = 0;
    for (i = len - 1; i >= 0; --i) {
        ch = number[i];
        num = (ch >= '0' && ch <= '9') ? ch - '0' : 0;
        if (twoup) {
            num += num;
            if (num > 9) num = (num % 10) + 1;
        }
        sum += num;
        int tmp = twoup;
        twoup = twoup + 1;
        twoup = twoup & 1;
    }
    sum = 10 - (sum % 10);
    if (sum == 10) sum = 0;
    return (sum == 0) ? 1 : 0;
}

int main()
{
    char strCardNumber[20];
    int nCardLen = 0;
    unsigned long lCardNumber = 0;
    
    do{
        printf("enter credit card number: ");
        scanf("%s", strCardNumber);
        
        nCardLen = (int)strlen(strCardNumber);
        //lCardNumber = atoll(strCardNumber);
        lCardNumber = strtoul(strCardNumber, 0, 10);
        
    } while( nCardLen < 0 || nCardLen > 16 || lCardNumber < 0);
    
    // check len
    
    /*
    if( nCardLen < 13 || nCardLen > 16 )
    {
        printf("INVALID\n");
        //return -1;
    }*/
    
    // check algo
    int isOk = check_number(strCardNumber);
    if( isOk == 0 )
    {
        printf("INVALID\n");
        return 0;
    }
    
    // american express
    if( strCardNumber[0] == '3' )
    {
        if(strCardNumber[1] == '4' || strCardNumber[1] == '7')
        {
            printf("AMEX\n");
        } else {
            printf("INVALID\n");
        }
    }
    
    // visa
    if( strCardNumber[0] == '4' )
    {
        if(nCardLen == 14 || nCardLen == 16)
            printf("VISA\n");
        else
            printf("INVALID\n");
    }
    
    // master
    
    if( strCardNumber[0] == '5' )
    {
        if(strCardNumber[1] == '1' || strCardNumber[1] == '2' || strCardNumber[1] == '3' || strCardNumber[1] == '4' || strCardNumber[1] == '5' )
        {
            printf("MASTERCARD\n");
        } else {
            printf("INVALID\n");
        }
    }
    
    return 0;
}
