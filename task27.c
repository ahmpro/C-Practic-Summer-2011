#include <stdio.h>
#include <stdlib.h>

void task27()
{
    char A[255];
    unsigned C[10] = {0}, i = 0;

    FILE *io = fopen("io\\27.output", "w");
    FILE *inp = fopen("io\\27.input", "r");

    printf("Used file 'io\\27.input'\n"); fprintf(io, "Used file 'io\\27.input'\n");

    fgets(A, 255, inp); 

    printf("A = "); fprintf(io, "A = ");

    while(A[i]>0){
        C[ A[i]-'0' ] += 1;
        printf("%c", A[i]);
        fprintf(io, "%c", A[i]);
        i++;
    }
    printf("\n"); fprintf(io, "\n");

    for(i=0;i<10;i++){
            fprintf(io, "%i :", i);
            for(;C[i]>0;C[i]--)
                fprintf(io, "*");
            fprintf(io, "\n");
    }
    fclose(io);
    fclose(inp);
}