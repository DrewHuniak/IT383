/* figure 4.9 in textbook
 */

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

//int sum; /* this data is shared by the thread(s) */
void *runner(void *param); /* the thread */


sem_t sem;

int main(int argc, char *argv[])
{
	pthread_t tid; /* the thread identifier */
	pthread_attr_t attr; /* set of thread attributes */

	if (argc !=2) {
		fprintf(stderr,"usage: a.out <integer value>\n");
		return -1;
	}
	if (atoi(argv[1]) < 0) {
		fprintf(stderr,"%d must be >=0\n",atoi(argv[1]));
		return -1;
	}
	
	/* Create the semaphore and initialize it to 1 */
	/* parameter 1: a pointer to the semaphore
	 * parameter 2: a flag indicating the level of sharing
	 * parameter 3: the semaphore's initial value
	 */
	//sem_init(&sem, 0, 1);
	sem_init(&sem, 0, 5);



	fprintf(stderr,"---Hello, I am parent thread. Now I am creating a new thread...\n");
	/* get the default attributes */
	pthread_attr_init(&attr);
	/* create the thread */
	/* NOTE: we use pthread_create rather than "fork" */
	pthread_create(&tid, &attr, runner,argv[1]);
	fprintf(stderr,"---Hello, I am parent thread. A new thread has been created..\n");

	/* acquire the semaphore */
	sem_wait(&sem);

	/* critical section
         */

	sem_post(&sem);
	
	fprintf(stderr,"---Hello, I am parent thread. Now I am waiting......\n");
	/* wait for the thread to exit */
	/* NOTE: we use pthread_join rather than "wait" */
	pthread_join(tid,NULL);
	fprintf(stderr,"---Hello, I am parent thread. Just confirmed that the new thread has finished its job......\n");
	
//	printf("sum = %d\n",sum);
}

/* The thread will begin control in this function */
void *runner(void *param)
{
	int i, upper = atoi(param);
//	sum = 0;

	fprintf(stderr,"---Hello, I am a newly created thread...\n");
	//thr_yield();
	pthread_yield();

	/* acquire the semaphore */
	sem_wait(&sem);
	/* critical section
         */
	/* release the semaphore */
	sem_post(&sem);

//	for (i=1; i <= upper; i++)
//		sum += i;

	/* NOTE: we need to call pthread_exit() to indicate that
         * thread is being terminated
         */
	pthread_exit(0);
}


