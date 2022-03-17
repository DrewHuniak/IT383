/* figure 4.9 in textbook
 */

#include <pthread.h>
#include <stdio.h>

int sum; /* this data is shared by the thread(s) */
void *runner(void *param); /* the thread */

pthread_mutex_t mutex;
int count = 0;

int main(int argc, char *argv[])
{
	pthread_t tid; /* the thread identifier */
	pthread_attr_t attr; /* set of thread attributes */

	if (argc !=2) {
		fprintf(stderr,"usage: a.out <initial integer value for count>\n");
		return -1;
	}
	if (atoi(argv[1]) < 0) {
		fprintf(stderr,"%d must be >=0\n",atoi(argv[1]));
		return -1;
	}

	count = atoi(argv[1]);

	/* create the mutex lock */
	int retval =  pthread_mutex_init(&mutex,NULL);


	fprintf(stderr,"---Hello, I am parent thread. Now I am creating a new thread...\n");
	/* get the default attributes */
	pthread_attr_init(&attr);
	/* create the thread */
	/* NOTE: we use pthread_create rather than "fork" */
	pthread_create(&tid, &attr, runner,argv[1]);


	/* acquire the mutex lock */
	pthread_mutex_lock(&mutex);


	count++;
	/**** critical section ****/

	/* release the mutex lock */
	pthread_mutex_unlock(&mutex);


	fprintf(stderr,"---Hello, I am parent thread. Now I am waiting......\n");
	/* wait for the thread to exit */
	/* NOTE: we use pthread_join rather than "wait" */
	pthread_join(tid,NULL);
	fprintf(stderr,"---Hello, I am parent thread. Just confirmed that the new thread has finished its job......\n");
	
	printf("count = %d\n",count);
}

/* The thread will begin control in this function */
void *runner(void *param)
{
	int i, upper = atoi(param);
	sum = 0;

	fprintf(stderr,"---Hello, I am a newly created thread...\n");
	//thr_yield();
	pthread_yield();
	/* acquire the mutex lock */
/*
	pthread_mutex_lock(&mutex);

	/**** critical section ****/
	count--;

	/* release the mutex lock */
	pthread_mutex_unlock(&mutex);
/*
	/* release the mutex lock */
	pthread_mutex_unlock(&mutex);

	/**** critical section ****/
	count--;
	pthread_mutex_lock(&mutex);




/*
	for (i=1; i <= upper; i++)
		sum += i;
*/

	/* NOTE: we need to call pthread_exit() to indicate that
         * thread is being terminated
         */
	pthread_exit(0);
}


