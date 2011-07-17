#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "task02.h"
#include "task05.h"
#include "task07.h"
#include "task11.h"
#include "task24.h"
#include "task26.h"
#include "task27.h"

int Task[32] = {0};
void (*Func[32])();

int main(){
    int n = 0;
    Task[2] = 1; Func[2] = task02;
    Task[5] = 1; Func[5] = task05;
    Task[7] = 1; Func[7] = task07;
    Task[11] = 1; Func[11] = task11;
    Task[24] = 1; Func[24] = task24;
    Task[26] = 1; Func[26] = task26;
    Task[27] = 1; Func[27] = task27;

    srand( (unsigned) time(NULL) );

    printf("Select Task: ");
    scanf_s("%d", &n);

    if ( (n>=1) & (n<=31) & (Task[n]) )
        Func[n]();
    else
        printf("Task incorrect or unavialable");

	return 0;
}