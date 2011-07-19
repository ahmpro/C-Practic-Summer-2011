#include <stdio.h>
#include <stdlib.h>

void task05()
{
    float A[10][10] = {0}, B[10][10] = {0}, C[10][10] = {0}, X[10][1] = {0};
    int i,j,n;
    float maxA, maxB, maxC;

    FILE *io = fopen("io\\05.output", "w");

    printf("Enter the number of dimensions: "); fprintf(io, "Enter the number of dimensions: ");
    scanf_s("%d",&n);
    fprintf(io, "%d\n", n);

    for(i=0; i<n; i++){
        for(j=0; j<n; j++)
        {
            A[i][j] = 0.0+rand()%30;
            B[i][j] = 0.0+rand()%30;
            C[i][j] = 0.0+rand()%30;
            X[i][1] += A[i][j]+B[i][j]+C[i][j];
        }
    }
    // Print A,B,C
    fprintf(io, "A:\n"); for(i=0; i<n; i++) { for(j=0; j<n; j++) { fprintf(io, "%8.3f ",A[i][j]); } fprintf(io, "\n"); }
    fprintf(io, "B:\n"); for(i=0; i<n; i++) { for(j=0; j<n; j++) { fprintf(io, "%8.3f ",B[i][j]); } fprintf(io, "\n"); }
    fprintf(io, "C:\n"); for(i=0; i<n; i++) { for(j=0; j<n; j++) { fprintf(io, "%8.3f ",C[i][j]); } fprintf(io, "\n"); }
    // Print X
    fprintf(io, "X:\n"); for(i=0; i<n; i++) { fprintf(io, "%8.3f\n",X[i][1]); }
    //
    maxA = A[0][0]; maxB = B[0][0]; maxC = C[0][0];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if ( A[i][j] > maxA )
                maxA = A[i][j];
            if ( B[i][j] > maxB )
                maxB = B[i][j];
            if ( C[i][j] > maxC )
                maxC = C[i][j];
        }
    }
    // print Charts
    fprintf(io, "\nmaxA(%3i): ", (int)maxA ); for(i=0;i<(int)maxA;i++) fprintf(io, "*");
    fprintf(io, "\nmaxB(%3i): ", (int)maxB ); for(i=0;i<(int)maxB;i++) fprintf(io, "*");
    fprintf(io, "\nmaxC(%3i): ", (int)maxC ); for(i=0;i<(int)maxC;i++) fprintf(io, "*");

    fclose(io);
}