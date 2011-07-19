#include <stdio.h>
#include <stdlib.h>

void task19()
{
    struct Teacher
    {
        char LastName[255];
        unsigned char Age;
        char Degree[255];
        char Subject[255];
        unsigned Hours;
    } Teachers[10];

    char S[255] = {1};
    unsigned int i = 0, k = 0, n = 0, average = 0;

    FILE *io = fopen("io\\19.output", "w");
    FILE *inp = fopen("io\\19.input", "r");

    printf("Used file 'io\\19.input'\n"); fprintf(io, "Used file 'io\\19.input'\n");

    fgets(S, 255, inp);
    while(S[i]>10) n = n*10 + (S[i++]-'0');

    while(k<n)
    {
        Teachers[k].Age = 0;
        Teachers[k].Hours = 0;
        fgets(S, 255, inp); i = 0; while(S[i]>10) Teachers[k].LastName[i] = S[i++]; Teachers[k].LastName[i] = 0;
        fgets(S, 255, inp); i = 0; while(S[i]>10) Teachers[k].Age = Teachers[k].Age*10 + (S[i++]-'0');
        fgets(S, 255, inp); i = 0; while(S[i]>10) Teachers[k].Degree[i] = S[i++]; Teachers[k].Degree[i] = 0;
        fgets(S, 255, inp); i = 0; while(S[i]>10) Teachers[k].Subject[i] = S[i++]; Teachers[k].Subject[i] = 0;
        fgets(S, 255, inp); i = 0; while(S[i]>10) Teachers[k].Hours = Teachers[k].Hours*10 + (S[i++]-'0');
        average += Teachers[k].Hours;
        k++;
    }
    average /= k;
    fprintf(io, "Average: %d\n",average);

    for(k=0;k<n;k++)
    {
        if (Teachers[k].Hours>average)
        {
            fprintf(io, "===\nLastname: ");
            i = 0; while(Teachers[k].LastName[i]>0) fprintf(io, "%c",Teachers[k].LastName[i++]);
            fprintf(io, "\nAge: %2i",Teachers[k].Age);
            fprintf(io, "\nDegree: ");
            i = 0; while(Teachers[k].Degree[i]>0) fprintf(io, "%c",Teachers[k].Degree[i++]);
            fprintf(io, "\nSubject: ");
            i = 0; while(Teachers[k].Subject[i]>0) fprintf(io, "%c",Teachers[k].Subject[i++]);
            fprintf(io, "\nHours: %2i\n",Teachers[k].Hours);
        }
    }

    fclose(io);
    fclose(inp);
}