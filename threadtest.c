#include "types.h"
#include "stat.h"
#include "user.h"
#define NUM_THREADS 2

void thread(void *args)
{
    printf(1, "\n");
}

int main()
{
    int i, j;
    void *stacks[NUM_THREADS];
	// Args
	int *args[NUM_THREADS];

	// Allocate stacks and args and make sure we have them all
	// Bail if something fails
	for (i=0; i<NUM_THREADS; i++) {
		stacks[i] = (void*) malloc(4096);
		if (!stacks[i]) {
			printf(1, "main: could not get stack for thread %d, exiting...\n");
			exit();
		}

		args[i] = (int*) malloc(4);
		if (!args[i]) {
			printf(1, "main: could not get memory (for arg) for thread %d, exiting...\n");
			exit();
		}

		*args[i] = i;
	}

	printf(1, "main: running with %d threads...\n", NUM_THREADS);

	// Start all children
	for (i=0; i<NUM_THREADS; i++) {
		int pid = clone(thread, args[i], stacks[i]);
		printf(1, "main: created thread with pid %d\n", pid);
	}
	
	// Wait for all children

	for (i=0; i<NUM_THREADS; i++) {
		void *joinstack;
		join(&joinstack);
		for (j=0; j<NUM_THREADS; j++) {
			if (joinstack == stacks[i]) {
				printf(1, "main: thread %d joined...\n", i);
				break;
			}
		}

	} 
	
    exit();
}
