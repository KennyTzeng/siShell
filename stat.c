#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

char* get_stat_type(mode_t mode);

void sh_stat(char* name) {

	if(name == NULL) {
		printf("usage: stat {file/dir}\n");
		return;
	}

	struct stat buf;
	if(!stat(name, &buf)) {
		
		printf("%6s: %-14s %6s: %s\n", "File", name, "Type", get_stat_type(buf.st_mode));
		printf("%6s: %-14lld %6s: %-10lld %8s: %ld\n", "Size", (long long)buf.st_size, "Blocks", (long long)buf.st_blocks, "IO BLOCK", (long)buf.st_blksize);
		printf("%6s: %-14ld %6s: %-10ld %8s: %ld\n", "Device", (long)buf.st_dev, "Inode", (long)buf.st_ino, "Links", (long)buf.st_nlink);
		printf("%6s: %-14lo %6s: %-10ld %8s: %ld\n", "Access", (unsigned long)buf.st_mode, "UID", (long)buf.st_uid, "GID", (long)buf.st_gid);
		printf("%6s: %s", "Access", ctime(&buf.st_atime));
		printf("%6s: %s", "Modify", ctime(&buf.st_mtime));
		printf("%6s: %s", "Change", ctime(&buf.st_ctime));

	}else {
		printf("stat: cannot stat \'%s\': No such file or directory\n", name);
	}

	return;
}

char* get_stat_type(mode_t mode) {
	char* type;
	if(S_ISREG(mode)) {
		type = "regular file";
	}else if(S_ISDIR(mode)) {
		type = "directoy";
	}else if(S_ISFIFO(mode)) {
		type = "FIFO";
	}else if(S_ISSOCK(mode)) {
		type = "socket";
	}else if(S_ISCHR(mode)) {
		type = "char device";
	}else if(S_ISBLK(mode)) {
		type = "block device";
	}else if(S_ISLNK(mode)) {
		type = "link";
	}else {
		type = "unknown";
	}
	return type;
}
