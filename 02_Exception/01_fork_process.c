/*
A simple example demonstrating the fork of a process.
Based on "Computer Systems" by Randal E. Bryant & David R. O'Hallaron
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
    pid_t pid;
    int x = 1;

    pid = Fork();

    if (pid == 0) {
        printf("\nchild: x = %d\n", ++x);
        exit(0);
    }
    printf("\nparent: x = %d\n", --x);

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
		unix_error("Fork error");
	return pid;
}


