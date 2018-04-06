#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <utime.h>
#include <fcntl.h>
#include <unistd.h>

void touch(char* filename) {

	if(filename == NULL) {
		printf("usage: touch {file}\n");
		return;
	}

	int fd;
	fd = open(filename, O_RDONLY);
	if(fd != -1) {
		if(!utime(filename, NULL)) {
			printf("touch file \'%s\' successfully\n", filename);
		}else {
			printf("touch file \'%s\' failed\n", filename);
		}
	}else {
		fd = open(filename, O_RDWR|O_CREAT, 0666);
		if(fd != -1) {
			printf("create file \'%s\' successfully because it does not exist previously\n", filename);
		}else {
			printf("create file \'%s\' failed and it does not exist previously\n", filename);
		}
	}
	close(fd);

	return;
}
