#include <stdio.h>
#include <stdlib.h>

void task05()
{
    float A[10][10] = {0}, B[10][10] = {0}, C[10][10] = {0}, X[10][1] = {0};
    int i,j,n;

    printf("Enter the number of dimensions: ");
    scanf_s("%d",&n);

    for(i=0; i<n; i++){
        for(j=0; j<n; j++)
        {
            A[i][j] = 1.0+rand()%15;
            B[i][j] = 1.0+rand()%15;
            C[i][j] = 1.0+rand()%15;
            X[i][1] += A[i][j]+B[i][j]+C[i][j];
        }
    }
    // Print A,B,C
    printf("A:\n");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%8.3f ",A[i][j]);
        }
        printf("\n");
    }
    printf("B:\n");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%8.3f ",B[i][j]);
        }
        printf("\n");
    }
    printf("C:\n");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%8.3f ",C[i][j]);
        }
        printf("\n");
    }
    // Print X
    printf("X:\n");
    for(i=0; i<n; i++){
        printf("%8.3f\n",X[i][1]);
    }
}