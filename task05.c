#include <stdio.h>
#include <stdlib.h>

void task05()
{
    float A[10][10] = {0}, B[10][10] = {0}, C[10][10] = {0}, X[10][1] = {0};
    int i,j,n;
    float maxA, maxB, maxC;

    printf("Enter the number of dimensions: ");
    scanf_s("%d",&n);

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
    printf("A:\n"); for(i=0; i<n; i++) { for(j=0; j<n; j++) { printf("%8.3f ",A[i][j]); } printf("\n"); }
    printf("B:\n"); for(i=0; i<n; i++) { for(j=0; j<n; j++) { printf("%8.3f ",B[i][j]); } printf("\n"); }
    printf("C:\n"); for(i=0; i<n; i++) { for(j=0; j<n; j++) { printf("%8.3f ",C[i][j]); } printf("\n"); }
    // Print X
    printf("X:\n"); for(i=0; i<n; i++) { printf("%8.3f\n",X[i][1]); }
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
    printf("\nmaxA(%3i): ", (int)maxA ); for(i=0;i<(int)maxA;i++) printf("*");
    printf("\nmaxB(%3i): ", (int)maxB ); for(i=0;i<(int)maxB;i++) printf("*");
    printf("\nmaxC(%3i): ", (int)maxC ); for(i=0;i<(int)maxC;i++) printf("*");
}