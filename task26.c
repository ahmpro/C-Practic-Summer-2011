#include <stdio.h>
#include <stdlib.h>

void task26()
{
    float A[10][10] = {0}, C[10][10] = {0}, X[10][1] = {0}, Bi, Chart[10] = {0};
    int n, i, j;

    FILE *io = fopen("io\\26.output", "w");

    printf("Enter the number of dimensions: "); fprintf(io, "Enter the number of dimensions: ");
    scanf_s("%d",&n);
    fprintf(io, "%d\n", n);

    if ( (n>10) & (n<2) )
    { fprintf(io, "Incorrect dimension"); }
    else
    {
        // fill A
        for(i=0; i<n; i++)
            for(j=0; j<n; j++) { A[i][j] = 0.0+rand()%15; }
        // Print A
        fprintf(io, "A:\n"); for(i=0; i<n; i++) { for(j=0; j<n; j++) fprintf(io, "%8.3f ",A[i][j]); fprintf(io, "\n"); }
        // C=A-E
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                C[i][j] = A[i][j] - ( (i==j) ? 1 : 0 );
        // X=CB
        for(i=0; i<n; i++)
            for(j=0; j<n; j++){
                Bi = (i%2==0) ? 1/(i*i+2.0) : 1.0/i;
                X[i][0] += C[i][j]*Bi;
            }
        // Print X
        fprintf(io, "X:\n"); for(i=0; i<n; i++) { fprintf(io, "%8.3f \n",X[i][0]); }
        //
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                Chart[i] += A[j][i];
            }
            Chart[i] /= n;
        }
        for(i=0;i<n;i++){
            fprintf(io, "%2i :", (int)Chart[i] );
            for(j=0;j<(int)Chart[i];j++)
                fprintf(io, "*");
            fprintf(io, "\n");
        }
    }
    fclose(io);
}