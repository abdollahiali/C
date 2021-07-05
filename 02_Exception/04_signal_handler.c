/*
Shows how to build and use a signal handler

Based on "Computer Systems" by Randal E. Bryant & David R. O'Hallaron
section 8.5, page 799

*/
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

void unix_error(char *msg);
void sigint_handler(int sig);


int  main(void)
{
    /*Install the signal handler*/
    if (signal(SIGINT, sigint_handler) == SIG_ERR)
        unix_error("signal error");
    
    printf("Infinite loop starts. Press Ctrl+C to see how SIGINT is handled.\n");
    //for(;;)
    //    ;
    pause();
    return 0;
}

void unix_error(char *msg)
{
	fprintf(stderr, "%s: %s\n", msg, strerror(errno));
	exit(0);
}


void sigint_handler(int sig)
{
    printf("\nCaught SIGINT!\n");
    exit(0);
}
