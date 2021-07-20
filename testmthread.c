#include "types.h"
#include "stat.h"
#include "user.h"
#include "mthread.c"

int x = 0;

void sum(void *y)
{
    for(;;) {
      x++;
      sleep(100);
    }
}

int main()
{
    int arr[] = {1};
    thread_create(&sum, (void *)arr);
    for(;;) {
        x++;
      printf(1, "x = %d\n", x);
      sleep(100);
    }

    exit(); 
}