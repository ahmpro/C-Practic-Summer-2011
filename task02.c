#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void task02()
{
    float A[10][10] = {0}, B[10][10] = {0}, D[10][10] = {0}, F[10][10] = {0};
    int i, j, n, k;
	float min, max;

    FILE *io = fopen("io\\02.output", "w");

    printf("Enter the number of dimensions: "); fprintf(io, "Enter the number of dimensions: ");
    scanf_s("%d",&n);
    fprintf(io, "%d\n", n);

    if ( (n>10) & (n<2) )
    { printf("Incorrect dimension"); }
    else
    {
        // fill A,B
        for(i=0; i<n; i++)
            for(j=0; j<n; j++) { A[i][j] = 0.0+rand()%15; B[i][j] = 0.0+rand()%15; }
        // Print A,B
        fprintf(io, "A:\n"); for(i=0; i<n; i++) { for(j=0; j<n; j++) fprintf(io, "%8.3f ",A[i][j]); fprintf(io, "\n"); }
        fprintf(io, "B:\n"); for(i=0; i<n; i++){ for(j=0; j<n; j++) fprintf(io, "%8.3f ",B[i][j]); fprintf(io, "\n"); }
        // F=B-E
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                F[i][j] = B[i][j] - ( (i==j) ? 1 : 0 );
        //D = AF+C
        for(i=0; i<n; i++)
            for(j=0; j<n; j++) {
                for(k=0; k<n; k++)
                    D[i][j] += A[i][k]*F[k][j];
                D[i][j] += sqrt((i^2+j^2)+0.0);
            }
        // Print D
        fprintf(io, "D:\n"); for(i=0; i<n; i++) { for(j=0; j<n; j++) fprintf(io, "%8.3f ",D[i][j]); fprintf(io, "\n"); }
		//
        max = D[0][0]; min = D[0][0];
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if ( (i==j) | ((n-i-1)==j) )
                {
                    if ( D[i][j] > max )
                        max = D[i][j];
                    if ( D[i][j] < min )
                        min = D[i][j];
                }
		fprintf(io, "min D = %f\n", min);
		fprintf(io, "max D = %f\n", max);
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if ( (i==j) | ((n-i-1)==j) )
                {
                    if ( D[i][j] == max )
                        D[i][j] = min;
                    else
                        if ( D[i][j] == min )
                            D[i][j] = max;
                }
		// Print swapped D
        fprintf(io, "Swapped  D:\n"); for(i=0; i<n; i++) { for(j=0; j<n; j++) fprintf(io, "%8.3f ",D[i][j]); fprintf(io, "\n"); }

        fclose(io);
	}
}