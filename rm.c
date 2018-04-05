#include <stdio.h>

void rm(char* filename) {
	
	if(filename == NULL) {
		printf("usage: rm {file}\n");
		return;
	}

	if(!remove(filename)) {
		printf("file - %s has been removed\n", filename);
	}else {
		printf("remove file - %s failed\n", filename);
	}

	return;
}
