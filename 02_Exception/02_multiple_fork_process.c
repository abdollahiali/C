/*
This exmple shows the two forks.
Note that when a process is forked using pid_i = Fork();
Then, the process will itself has a nonzero pid (which can be obtained using getpid() function), but pid_i is zero inside the child process
and it is equal to the forked process ID in the parent process.

The following example we see pid, pid1 and pid2 in the four process created by the following example and assuming that the original parent process
has pid of 77

													 -----pid:80, pid1:  0, pid2:  0
													|
													|
													|
													|
													|
						 -----pid:78, pid1:0-----Fork-----pid:78, pid1:  0, pid2: 80
						|
						|
						|
						|							 -----pid:79, pid1: 78, pid2:  0
						|							|
						|							|
						|							|
						|							|
						|							|
main-----pid:77-----Fork-----pid:77, pid1:78-----Fork-----pid:77, pid1: 78, pid2: 79


Therefore, in the case the output of the program is as follows:

porcess pid:    77, pid1:     78, pid2:     79
porcess pid:    78, pid1:      0, pid2:     80
porcess pid:    79, pid1:     78, pid2:      0
porcess pid:    80, pid1:      0, pid2:      0

*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void unix_error(char *msg);
pid_t Fork(void);

int main ()
{
    pid_t pid, pid1, pid2;

    pid1 = Fork();
	pid2 = Fork();
	

   /* if (pid1 == 0) {
        printf("\nchild: pid1\n");
        exit(0);
    }
    if (pid2 == 0) {
        printf("\nchild: pid2\n");
        exit(0);
    }
    printf("\nparent\n");
	*/
	
	pid = getpid();
	
	printf("porcess pid: %5d, pid1: %5d, pid2: %5d\n", pid, pid1, pid2);

	return 0;
}

void unix_error(char *msg)
{
	fprintf(stderr, "%s: %s\n", msg, strerror(errno));
	exit(0);
}

pid_t Fork(void)
{
	pid_t pid;
	
	if ((pid = fork()) < 0)
		unix_error("Fork Error");
	return pid;
}


