all: pthreadtest pthreadtest2 pthread_sem pthread_mutex thread_sched	pthread_mutex_deadlock

pthreadtest: pthreadtest.c
	gcc -o pthreadtest pthreadtest.c  -lpthread

pthreadtest2: pthreadtest2.c
	gcc -o pthreadtest2 pthreadtest2.c -lpthread

pthread_sem: pthread_sem.c
	gcc -o pthread_sem pthread_sem.c -pthread -lrt

pthread_mutex: pthread_mutex.c
	gcc -o pthread_mutex pthread_mutex.c -pthread -lrt

pthread_mutex_deadlock: pthread_mutex_deadlock.c
	gcc -o pthread_mutex_deadlock pthread_mutex_deadlock.c -pthread -lrt

thread_sched:	thread_sched.c
	gcc -o thread_sched thread_sched.c -pthread -lrt
