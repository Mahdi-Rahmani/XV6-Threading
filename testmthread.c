#include "types.h"
#include "stat.h"
#include "user.h"
#include "mthread.c"

int arrsum = 0;
int arr[] = {1, 2, 3, 4, 5, 6}; // 1 + 2 + 3 + 4 + 5 + 6 = 21

void sum(void *x)
{
    arrsum += *((int *)x);
    return;
}

int main()
{
    for(int i = 0; i < 6; i++)
    {
        thread_create(&sum, (void *)&arr[i]);
    }
    for(int i = 0; i < 6; i++)
    {
        thread_join();
    }
    printf(1, "**************");
    printf(1,"*%d\n", arrsum);

    exit(); 
}