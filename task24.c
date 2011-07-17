#include <stdio.h>
#include <stdlib.h>

void task24()
{
    unsigned int n = 601, A[602] = {0}, i, k = 2;

    while ( k < n/2 ){
        for(i=k*k;i<n;i++){
            if ( i%k == 0 ) A[i] = 1;
        }
        do k++; while(A[k]);
    }

    for(i=100;i<601;i++) if (!A[i]) printf("%i ", i);
    
    printf("\n");
}