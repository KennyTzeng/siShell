#include <stdio.h>
#include <unistd.h>

void sh_rmdir(char* dir) {

	if(dir == NULL) {
		printf("usage: rmdir {dir}\n");
		return;
	}

	if(!rmdir(dir)) {
		printf("remove an empty directory - %s successfully\n", dir);
	}else {
		printf("remove an empty directory - %s failed\n", dir);
	}
	
	return;
}
