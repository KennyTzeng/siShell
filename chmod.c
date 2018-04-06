#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

void sh_chmod(char* mode, char* name) {
	
	if(mode == NULL || name == NULL) {
		printf("usage: chmod {mode} {file/dir}\n");
		printf("{mode} is an octal number\n");
		return;
	}

	if(!chmod(name, strtol(mode, NULL, 8))) {
		printf("change file \'%s\' permission to %03lo successfully\n", name, strtol(mode, NULL, 8));
	}else {
		printf("change file \'%s\' permission to %03lo failed\n", name, strtol(mode, NULL, 8));
	}

	return;
}
