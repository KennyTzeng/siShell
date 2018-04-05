#include <stdio.h>
#include <unistd.h>

void pwd() {
	
	char buf[80];
	getcwd(buf, sizeof(buf));
	printf("%s\n", buf);
	return;
}

