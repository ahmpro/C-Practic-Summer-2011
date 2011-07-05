#include <stdio.h>

#include "task02.h"
#include "task05.h"

int Task[32] = {0};
void (*Func[32])();

int main(){
    int n = 0;
    Task[2] = 1; Func[2] = task02;
    Task[5] = 1; Func[5] = task05;

    printf("Select Task: ");
    scanf_s("%d", &n);

    if ( (n<1) & (n>31) )
    { printf("Incorrect task"); }
    else
    {
        if (!Task[n])
        { printf("Task is unavailable\n"); }
        else
        {
            Func[n]();
        }
    }

	return 0;
}