#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void task11()
{
    char S[255];
    unsigned int i = 0, k = 0;
    float C[26] = {0};

    FILE *io = fopen("io\\11.output", "w");
    FILE *inp = fopen("io\\11.input", "r");

    printf("Used file 'io\\11.input'\n"); fprintf(io, "Used file 'io\\11.input'\n");
    fgets(S, 255, inp);

    while(S[i]>0)
    {
        if ( S[i] > 90 )
            S[i] -= 32; // upper
        if ( (S[i] >=65) | (S[i] <=90) )
        {
            C[ S[i]-'A' ] += 1;
            k++;
        }
        i++;
    }

    for(i=0;i<26;i++)
    {
        if (C[i]>0)
        {
            C[i] /= k*0.01;
            printf("%c: ",i+'A'); fprintf(io, "%c (%5.2f%%): ",i+'A',C[i]);
            for(;C[i]>0;C[i]--)
            {
                printf("*"); fprintf(io, "*");
            }
            printf("\n"); fprintf(io, "\n");
        }
    }

    fclose(io);
    fclose(inp);
}