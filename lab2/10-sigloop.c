#include <stdlib.h>
#include <signal.h>
#include <stddef.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>
#include <string.h>
#include <errno.h>

sigset_t ss;


struct sigaction newact;
struct sigaction usr2act;
int proceed;


void intr(int code) {
	proceed = 0;
}


void usr2(int code) {
	fprintf(stderr, "\nUSR2");
	exit(1);
}


int main(int argc, char** argv)
{
	int i;
	sigset_t block_set;
	sigset_t received_set;

	sigemptyset(&ss);
//	sigaddset(&ss, SIGINT);
	newact.sa_mask = ss;	

	proceed = 1;	

	newact.sa_handler = intr;
	newact.sa_flags = 0;
	if (sigaction(SIGALRM, &newact, NULL) == -1) exit(1);

	usr2act.sa_handler = usr2;
	usr2act.sa_flags = 0;
	if (sigaction(SIGUSR2, &usr2act, NULL) == -1) exit(1);
	
	alarm(10);
	/*sigaddset(&block_set, SIGINT);
	sigprocmask(SIG_BLOCK, &block_set, &received_set);*/
	fprintf(stderr, "Entering loooooOoOoop\n");
	while(proceed)
		printf("HURRDURR - %d\n", i);
	fprintf(stderr, "Done looooooOoping\n");
	sigpending(&received_set);
	
	for(i=0; i < _NSIG-1; ++i)
		if(sigismember(&received_set, i)) fprintf(stderr, "BLOCKED: SIG-%d\n", i );
	//sigprocmask(SIG_UNBLOCK, &block_set, &received_set);


	return 0;
}

/*void ( *signal(int signum, void (*handler)(int)) ) (int);*/

