#include <stdio.h>
#include <stdlib.h>

void task27()
{
    unsigned long A;
    unsigned C[10] = {0}, i;

    printf("Enter A: ");
    scanf_s("%li", &A);

    while(A>0){
        C[ A%10 ] += 1;
        A /= 10;
    }

    for(i=0;i<10;i++){
            printf("%i :", i);
            for(;C[i]>0;C[i]--)
                printf("*");
            printf("\n");
    }
}