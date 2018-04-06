#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

void print_info(char* name, char* type, long long int size);
char* get_dirp_type(int d_type);

void find(char* dir) {
	
	DIR *dp;
	struct dirent *dirp;
	if(dir == NULL) {
		if((dp = opendir(".")) == NULL) {
			printf("cannot open directory .\n");
		}else {
			while((dirp = readdir(dp)) != NULL) {
				struct stat buf;
				stat(dirp->d_name, &buf);
				print_info(dirp->d_name, get_dirp_type(dirp->d_type), (long long)buf.st_size);
			}
		}
	}else {
		if((dp = opendir(dir)) == NULL) {
			printf("cannot open directory %s\n", dir);
		}else {
			char pwd[80];
			getcwd(pwd, sizeof(pwd));
			chdir(dir);
			while((dirp = readdir(dp)) != NULL) {
				struct stat buf;
				stat(dirp->d_name, &buf);
				print_info(dirp->d_name, get_dirp_type(dirp->d_type), (long long)buf.st_size);
			}
			chdir(pwd);
		}
	}
	
	closedir(dp);
	free(dirp);
	return;
}

void print_info(char* name, char* type, long long int size) {
	printf("%-20s %-15s %lld\n", name, type, size);
}

char* get_dirp_type(int d_type) {

	char* type;
	switch(d_type){
		case DT_REG:
			type = "file";
			break;
		case DT_DIR:
			type = "directory";
			break;
		case DT_FIFO:
			type = "FIFO";
			break;
		case DT_SOCK:
			type = "socket";
			break;
		case DT_CHR:
			type = "char device";
			break;
		case DT_BLK:
			type = "block device";
			break;
		case DT_LNK:
			type = "symbolic link";
			break;
		default:
			type = "unknown";
	}
	return type;
}
