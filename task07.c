#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void task07()
{
    float M[10][10] = {0}, B[10][1] = {0}, sum = 0.0;
    int i, j, n, k = 0;
	float min, max;

    printf("Enter the number of dimensions: ");
    scanf_s("%d",&n);

    if ( (n>10) & (n<2) )
    { printf("Incorrect dimension"); }
    else
    {
        // fill M
        for(i=0; i<n; i++)
            for(j=0; j<n; j++) { M[i][j] = 0.0+rand()%15; }
        // Print M
        printf("M:\n"); for(i=0; i<n; i++) { for(j=0; j<n; j++) printf("%8.3f ",M[i][j]); printf("\n"); }
        //
        for(i=0;i<n;i++){
            min = M[0][i];
            for(j=0;j<n;j++){
                if ( M[j][i] < min )
                    min = M[j][i];
            }
            B[i][0] = min;
        }
        // Print B
        printf("B:\n"); for(i=0; i<n; i++) { printf("%8.3f \n", B[i][0]); }
        // find max in (j<i)
        max = M[1][0];
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if ( j<i )
                    if ( M[i][j] > max )
                        max = M[i][j];
        // compare max with (j>=i)
        for(i=0;i<n;i++){
            for(j=0;j<n;j++)
                if ( j>=i )
                    if ( M[i][j] > max )
                    {
                        sum += M[i][j];
                        k++;
                    }
        }
        if (!k)
            printf("Elements not found.\n");
        else
            printf("Sum = %.2f\n", sum);

        printf("Enter the number for check: ");
        scanf_s("%d",&k);
        j = 0;
        for(i=0;i<n;i++){
            if ( M[i][i] == k )
            {
                printf("Yes");
                j = -1;
                break;
            }
        }
        if ( !j ) printf("No");
    }
}