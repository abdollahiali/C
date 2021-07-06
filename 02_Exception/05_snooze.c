/*
Solution of practice problem 8.7 of "Computer Systems" by Randal E. Bryant & David R. O'Hallaron
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <string.h>

void sigint_handler_wakeup(int sig);
void sigint_handler_main(int sig);
void unix_error(char *msg);
unsigned int wakeup(unsigned int secs);



int main(int argc, char *argv[]) 
{
    int secs = 3; // default value is set to 3
    

    
    if (argc > 1)
        secs = atoi(argv[1]);
    wakeup(secs);
    
    /*Install the signal handler*/
    if (signal(SIGINT, sigint_handler_main) == SIG_ERR)
        unix_error("signal error");
    
    //signal(SIGINT, SIG_DFL); // This can be used to return to the default behaviour of SIGINT
    
    printf("\nWait in infinite loop. Use Ctrl+C to exit.\n");
    for(;;)
        ;
    
    return 0;
}

void sigint_handler_wakeup(int sig)
{
    printf("\nSIGINT handler used in wakeup() function.\n");
    return;
}

void sigint_handler_main(int sig)
{
    printf("\nSIGINT handler used in main() function.\n");
    exit(0);
}

void unix_error(char *msg)
{
	fprintf(stderr, "%s: %s\n", msg, strerror(errno));
	exit(0);
}


unsigned int wakeup(unsigned int secs)
{
    /*Install the signal handler*/
    if (signal(SIGINT, sigint_handler_wakeup) == SIG_ERR)
        unix_error("signal error");
    
    unsigned int rc = sleep(secs);
    
    printf("\nSlept %d seconds of total %d seconds.\n", secs-rc, secs);
    return rc;
}
