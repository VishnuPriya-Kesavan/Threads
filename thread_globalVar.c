
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

void *runner (void *param); /* the thread */
int global_a = 0; /* global variable shared by all threads */

int main (int argc, int argv[])
{
	pthread_t tid[10]; /* the thread identifiers 10 threads */
	int i;

	
	/*create the threads */
	for (i=0; i<10; i++)
		pthread_create(&tid[i], NULL, runner, NULL);

	
	/* wait for the threads to exit */
	for (i=0; i<10; i++)
		pthread_join (tid[i], NULL);
	

	printf ("global_a = %d\n", global_a);
	printf ("I am a process with id %ld and I am going to terminate now\n", (long)getpid());
}

/* The thread will begin control in this function */
void *runner (void *param)
{
	int i;

	global_a += (int)pthread_self();

	for (i=0; i<1000; i++);
	printf ("I am thread %ld and the value of global_a = %d\n", (long)pthread_self(), global_a); 

	pthread_exit(NULL);
}

