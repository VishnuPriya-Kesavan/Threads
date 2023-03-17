
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
void *runner (void *param); /* the thread */

int main (int argc, int argv[])
{
	pthread_t tid; /* the thread identifier */
	pthread_attr_t attr; /* set of thread attributes */

	
	/* get the default attributes */
	pthread_attr_init (&attr);
	
	/*create the thread */
	pthread_create(&tid, &attr, runner, NULL);
	
	/* wait for the thread to exit */
	//pthread_join (tid, NULL);

	printf ("I am a process and my process id is %ld\n", (long)getpid());
	printf ("I am a process and the thread with id %ld that I created has terminated\n",(long) tid);
}

/* The thread will begin control in this function */
void *runner (void *param)
{
	/* The function pthread_self() returns the ID of this thread */
	printf ("I am a thread and my id is %ld.\n",(long) pthread_self());
	printf ("I am a thread and I am now going to terminate.\n");

	pthread_exit(NULL);
}


