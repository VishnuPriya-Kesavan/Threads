#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

void *runner (void *param); /* the thread */

int main (int argc, int argv[])
{
	pthread_t tid1; /* the thread identifier for the first thread */
	pthread_t tid2; /* the thread identifier for the second thread */
	
	/*create the threads */
	pthread_create(&tid1, NULL, runner, "OS rocks! :)");
	pthread_create(&tid2, NULL, runner, "OS sucks! :(");
	
	/* wait for the threads to exit */
	pthread_join (tid1, NULL);
	pthread_join (tid2, NULL);

	printf ("I am a process with id %d and I am going to terminate now\n", getpid());
}

/* The thread will begin control in this function */
void *runner (void *param)
{

	printf ("I am thread %ld and am printing out %s\n", (long)pthread_self(), (char *)param);

	pthread_exit(NULL);
}



