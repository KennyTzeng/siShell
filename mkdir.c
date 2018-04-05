#include <stdio.h>
#include <sys/stat.h>

void sh_mkdir(char* dir) {

	if(dir == NULL) {
		printf("usage: mkdir {dir}\n");
		return;
	}

	if(!mkdir(dir, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH)) {
		printf("new directory - %s has been created\n", dir);
	}else {
		printf("creat a new directory - %s failed\n", dir);
	}

	return;
}
