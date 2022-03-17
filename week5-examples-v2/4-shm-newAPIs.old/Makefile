all: mmap_test shm_producer shm_consumer

mmap_test: mmap_test.c
	gcc -o mmap_test mmap_test.c

shm_producer: shm_producer.c
	gcc -o shm_producer shm_producer.c -lrt

shm_consumer: shm_consumer.c
	gcc -o shm_consumer shm_consumer.c -lrt
