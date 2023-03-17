
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

void *hello (void *param); /* function for the first thread */
void *bye (void *param); /* function for the second thread */

int main (int argc, int argv[])
{
	pthread_t tid1; /* the thread identifier for the first thread */
	pthread_t tid2; /* the thread identifier for the second thread */
	
	/**********************create the threads here ********************/
	
   /*create the threads */
	pthread_create(&tid1, NULL, hello,"!" );
	pthread_create(&tid2, NULL, bye, "!!");



	
	/* wait for the threads to exit */
	pthread_join (tid1, NULL);
	pthread_join (tid2, NULL);

	printf ("I am a process with id %ld and I am going to terminate now\n", (long)getpid());
}

void *hello (void *param)
{

	printf ("I am thread %ld and am printing out hello\n", (long)pthread_self());

	pthread_exit(NULL);
}

void *bye (void *param)
{

	printf ("I am thread %ld and am printing out bye\n", (long)pthread_self());

	pthread_exit(NULL);
}


