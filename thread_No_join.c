#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

void *runner (void *param); /* the thread */

int main (int argc, int argv[])
{
	pthread_t tid; /* the thread identifier */
	pthread_attr_t attr; /* set of thread attributes */

	
	/* get the default attributes */
	pthread_attr_init (&attr);
	
	/*create the thread */
	pthread_create(&tid, &attr, runner, NULL);

	printf ("I am a process with id %ld and I am going to terminate now\n", (long)getpid());
}

/* The thread will begin control in this function */
void *runner (void *param)
{
	int i;

	/* Print out the numbers from 1 to 1000 */
	for (i=1; i<=1000; i++)
		printf ("I am thread %ld and am printing out i=%d\n", (long)pthread_self(), i);
 
	printf ("I am thread %ld and I am now going to terminate.\n", (long)pthread_self());

	 pthread_exit(NULL);
	 }

