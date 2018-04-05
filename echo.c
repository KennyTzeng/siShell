#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

void echo(char* str, char* filename) {

	if(str == NULL) {
		printf("usage: echo {str} [filename]\n");
		return;
	}

	if(filename == NULL) {
		printf("%s\n", str);
	}else {
		int fd;
		fd = open(filename, O_WRONLY|O_APPEND);
		if(fd != -1) {
			strcat(str, "\n");
			write(fd, str, strlen(str));
		} else {
			printf("can't append \"%s\" to file %s, file doesn't exists\n", str, filename);
		}
		close(fd);
	}

	return;

}
