/*
This exmple shows the two forks.
Note that when a process is forked using pid_i = Fork();
Then, the process will itself has a nonzero pid (which can be obtained using getpid() function), but pid_i is zero inside the child process
and it is equal to the forked process ID in the parent process.

In this code we have a loop that is run for three times and each time makes a fork.
We show the counter (i) and also the pid that fork returns and then we show the counter and the pid of process
In total the following program creates 8 processes.
Note that the processes may run in different orders.

The following example show the result of one run.
For brevity, we have shown 
"i = x, fork_pid    = y" as "ix, fy"
"i = x, pid_process = y" as "ix, py"
We have also assumed that original parent process has pid of 7
The horizental axis shows the time (qualitatively), so we can see how the operating system changes the order of running the processes
The vertical dots shows the transitions from one process to another (the end of dot line is shown uisng star (*)).


																																																					   -----------------------------------------------i2, f0---i2, p13--E
																																																					  |											  *						.
																																																					  |											  .						.
																																																					  |											  .						.
																																																					  |											  .						.
																					   ---------------------------------------------------------------------------------------------------------i1, f0---i1, p10---Fork---i2, f13---i2, p10--E					  .						.
																					  |																										 *												 .					  .						.
																					  |																										 .												 .					  .						.
																					  |																										 .												 .					  .						.
																					  |															  -------------------------i2, f0---i2, p12--E												 .					  .						.
																					  |															 |					   *																	 .					  .						.
																					  |															 |					   .																	 .					  .						.
																					  |															 |					   .																	 .					  .						.
																					  |															 |					   .																	 .					  .						.
				 ---------------------i0, f0---i0, p8------------------------------Fork---i1, f10-----------------------i1, p8----------------Fork---i2, f12---i2, p8--E																	 .					  .						.
				|					 *				   .						 *					.			 	  *			.		   *														       									 .					  .						.
				|					 .				   .						 .					.			 	  .			.		   .														       									 .					  .						.
				|					 .				   .						 .					.			 	  .			.		   .														       									 .					  .						.
				|					 .				   .						 .					.			 	  .			.		   .														       									 .					  .						.
				|					 .				   .						 .					.			 	  .			.		   .														       									 .					  .						.						  -------------------------i2, f0---i2, p14--E
				|					 .				   .						 .					.			 	  .			.		   .														       									 .					  .						.						 |					   *
				|					 .				   .						 .					.			 	  .			.		   .														       									 .					  .						.						 |					   .
				|					 .				   .						 .					.			 	  .			.		   .														       									 .					  .						.						 |					   .
				|					 .				   .						 .					.			 	  .			.		   .														       									 .					  .						.						 |					   .
				|					 .				   .						 .					.			 	  .			.		   .														       									 .					  .						*						 |					   .
				|					 .				   .	 --------------------.------------------.-----------------.---------.------------------------------------------------------------------------------------------------------------.--------------------.-------------------------i1, f0---i1, p9---Fork---i2, f14---i2, p9--E
				|					 .				   .	|					 .					.			 	  .			.		   .														       									 .					  .
				|					 .				   .	|					 .					.			 	  .			.		   .														       									 .					  .
				|					 .				   .	|					 .					.			 	  .			.		   .														       									 *					  .
				|					 .				   .	|					 .					.	  ------------.---------.---------------------------------------------------------------------------------------------------------------i2, f0---i2, p11--E
				|					 .				   .	|					 .					.	 |			  .			.		   .
				|					 .				   .	|					 .					.	 |			  .			.		   .
				|					 .				   .	|					 .					.	 |			  .			.		   .
				|					 .				   *	|					 .					*	 |			  .			*		   .
main--pid:7--Fork---i0, f8---i0, p7----------------------Fork---i1, f9---i1, p7-----------------------Fork---i2, f11---------------i2, p7--E


The following shows the result of one run of the program that matches with the above diagram (excpet for a bias of 20000 in the pid numbers)

i = 0, fork_pid    = 20008
i = 0, process_pid = 20007
i = 0, fork_pid    =     0
i = 0, process_pid = 20008
i = 1, fork_pid    = 20009
i = 1, process_pid = 20007
i = 1, fork_pid    = 20010
i = 2, fork_pid    = 20011
i = 1, process_pid = 20008
i = 2, process_pid = 20007
i = 2, fork_pid    = 20012
i = 2, process_pid = 20008
i = 2, fork_pid    =     0
i = 2, process_pid = 20012
i = 1, fork_pid    =     0
i = 1, process_pid = 20010
i = 2, fork_pid    = 20013
i = 2, process_pid = 20010
i = 2, fork_pid    =     0
i = 2, process_pid = 20011
i = 2, fork_pid    =     0
i = 2, process_pid = 20013
i = 1, fork_pid    =     0
i = 1, process_pid = 20009
i = 2, fork_pid    = 20014
i = 2, process_pid = 20009
i = 2, fork_pid    =     0
i = 2, process_pid = 20014

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
	int i;
	
	for(i=0; i<3; i++) {
		pid = Fork();
		printf("i = %d, fork_pid    = %5d\n", i, pid);
		pid = getpid();
		printf("i = %d, pid_process = %5d\n", i, pid);
	}

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


