#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

void sh_umask(char* mode) {
	
	if(mode == NULL) {
		printf("usage: umask {mode}\n");
		printf("{mode} is an octal number\n");
		return;
	}

	umask(strtol(mode, NULL, 8));
	printf("the umask value is %03lo now\n", strtol(mode, NULL, 8));

	return;
}
