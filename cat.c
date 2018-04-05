#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

void cat(char* filename) {

	if(filename == NULL) {
		printf("usage: cat {file}\n");
		return;
	}

	int fd;
	char buf[200];
	fd = open(filename, O_RDONLY);
	if(fd != -1) {
		read(fd, buf, sizeof(buf));
		printf("%s\n", buf);
	}else {
		printf("cat: %s: No such file or directory\n", filename);
	}
	close(fd);

	return;

}
