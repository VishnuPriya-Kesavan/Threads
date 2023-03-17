
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include<stdlib.h>
void *runner (void *param); /* the thread */

int main (int argc, int argv[])
{
	pthread_t tid; /* the thread identifier */
	pthread_attr_t attr; /* set of thread attributes */

	
	/* get the default attributes */
	pthread_attr_init (&attr);
	
	/*create the thread */
	pthread_create(&tid, &attr, runner, "5");
	
	/* wait for the thread to exit */
	pthread_join (tid, NULL);

	printf ("I am a process and my process id is %ld\n", (long)getpid());
	printf ("I am a process and the thread with id %ld that I created has terminated\n",(long)tid);
}

/* The thread will begin control in this function */
/* This function calculates the sum = 1+...+atoi(param) */
void *runner (void *param)
{
	int i;
	int upper = atoi(param); /* The function atoi() converts a string to an integer */
	int sum = 0;

	for (i=1; i<=upper; i++)
		sum += i;

	/* The function pthread_self() returns the ID of this thread */
	printf ("I am a thread with id %ld and I have calculated the sum = %d\n.", (long)pthread_self(), sum);

	pthread_exit(NULL);
}

