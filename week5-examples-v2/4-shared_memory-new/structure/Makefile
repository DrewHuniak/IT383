all: shm_producer2 shm_consumer2 

shm_producer2: shm_producer2.c
	gcc -o shm_producer2 shm_producer2.c -lrt

shm_consumer2: shm_consumer2.c
	gcc -o shm_consumer2 shm_consumer2.c -lrt

clean:
	rm *.o shm_producer2 shm_consumer2
