#include <unistd.h>
#include <stdio.h>

void pwd();

void cd(char *dir) {
	
	if(dir == NULL) {
		printf("usage: cd {directory}\n");
	}else {
		if(chdir(dir)) {
			printf("cd: no such file or directory: %s\n", dir);
		}else {
			printf("current working directory: ");
			pwd();
		}
	}

	return;
	
}
