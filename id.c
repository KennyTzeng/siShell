#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void id() {

	printf("euid = %d , egid = %d\n", geteuid(), getegid());
	return;
}
