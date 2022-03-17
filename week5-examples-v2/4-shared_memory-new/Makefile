all: shm_producer shm_consumer mmap_test mmap_test2 mmap_test2_incorrect mmap_filecopy

shm_producer: shm_producer.c
	gcc -o shm_producer shm_producer.c -lrt

shm_consumer: shm_consumer.c
	gcc -o shm_consumer shm_consumer.c -lrt

mmap_test: mmap_test.c
	gcc -o mmap_test mmap_test.c

mmap_test2: mmap_test2.c
	gcc -o mmap_test2 mmap_test2.c

mmap_test2_incorrect: mmap_test2_incorrect.c
	gcc -o mmap_test2_incorrect mmap_test2_incorrect.c

mmap_filecopy: mmap_filecopy.c
	gcc -o mmap_filecopy mmap_filecopy.c

clean:
	rm *.o shm_producer shm_consumer
