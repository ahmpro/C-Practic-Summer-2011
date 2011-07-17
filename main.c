#include <stdio.h>

#include "task02.h"
#include "task05.h"
#include "task24.h"

int Task[32] = {0};
void (*Func[32])();

int main(){
    int n = 0;
    Task[2] = 1; Func[2] = task02;
    Task[5] = 1; Func[5] = task05;
    Task[24] = 1; Func[24] = task24;

    printf("Select Task: ");
    scanf_s("%d", &n);

    if ( (n<1) & (n>31) | !Task[n])
        printf("Task incorrect or unavialable");
    else
        Func[n]();

	return 0;
}