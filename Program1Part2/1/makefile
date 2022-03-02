all: uploader downloader

uploader : shm_fileuploader.c
	gcc -o shm_fileuploader shm_fileuploader.c -lrt

downloader: shm_filedownloader.c
	gcc -o shm_filedownloader shm_filedownloader.c -lrt

clean:
	rm shm_filedownloader shm_fileuploader