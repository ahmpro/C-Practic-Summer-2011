#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void task11()
{
    char S[256], Number[256];
    int i = 0, j;

    while ( ( S[i]=getchar() ) != '\n')
        i++;
    S[i]='\0';

    i = 0;
    while( S[i] != '\0' ){
        Number[S[i]] += 1;
        i++;
    }

    for(i=0;i<256;i++){
        if( Number[i] > 0 ){
            printf("%c",i);
            for(j=0;j<Number[i];j++)
                printf("*");
            printf("\n");
        }
    }
}