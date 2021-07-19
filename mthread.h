#include "types.h"
#include "param.h"
#include "syscall.h"
#include "traps.h"
#include "fs.h"
#include "mmu.h"

// int stack[4096] __attribute__ ((aligned (4096)));

int thread_create(void (*fn) (void), void *arg)
{
    //fn();
    //sleep(1);
    void *ptr = malloc(2 * PGSIZE);

    if ((uint)ptr%PGSIZE)
        ptr += PGSIZE - (uint) ptr%PGSIZE;

    int tid = clone(ptr);
    //printf(1, "We are here");
    if (tid < 0)
    {
        return -1;
    }
    else if (tid == 0)
    {
        printf(1, "Here\n");
        printf(1, "TTTTTt\n");
        (*fn)();
        printf(1, "###");
        free(ptr);
        exit();
    }
    else
    {
        sleep(5);
        return tid;
    }
}

int thread_join(void)
{
    return join();
}