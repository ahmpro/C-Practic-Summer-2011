#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void task07()
{
    float M[10][10] = {0}, B[10][1] = {0}, sum = 0.0;
    int i, j, n, k = 0;
	float min, max;

    FILE *io = fopen("io\\07.output", "w");

    printf("Enter the number of dimensions: "); fprintf(io, "Enter the number of dimensions: ");
    scanf_s("%d",&n);
    fprintf(io, "%d\n", n);

    if ( (n>10) & (n<2) )
    { fprintf(io, "Incorrect dimension"); }
    else
    {
        // fill M
        for(i=0; i<n; i++)
            for(j=0; j<n; j++) { M[i][j] = 0.0+rand()%15; }
        // Print M
        fprintf(io, "M:\n"); for(i=0; i<n; i++) { for(j=0; j<n; j++) fprintf(io, "%8.3f ",M[i][j]); fprintf(io, "\n"); }
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
        fprintf(io, "B:\n"); for(i=0; i<n; i++) { fprintf(io, "%8.3f \n", B[i][0]); }
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
            fprintf(io, "Elements not found.\n");
        else
            fprintf(io, "Sum = %.2f\n", sum);

        fprintf(io, "Enter the number for check: ");
        printf("Enter the number for check: ");
        scanf_s("%d",&k);
        fprintf(io, "%d\n", k);

        j = 0;
        for(i=0;i<n;i++){
            if ( M[i][i] == k )
            {
                fprintf(io, "Yes");
                j = -1;
                break;
            }
        }
        if ( !j ) fprintf(io, "No");
    }
    fclose(io);
}