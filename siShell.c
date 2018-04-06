#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

void sh_loop();
void type_prompt();
char* sh_read_input();
char** sh_split_input(char* input);
void exec_instr(char** args);

void cat(char* filename);
void cd(char* dir);
void sh_chmod(char* mode, char* name);
void echo(char* str, char* filename);
void find(char* dir);
void help();
void id();
void sh_mkdir(char* dir);
void pwd();
void rm(char* filename);
void sh_rmdir(char* dir);
void sh_stat(char* name);
void touch(char* filename);
void sh_umask(char* mode);

#define input_bufSize 1024
#define tok_bufSize 64
#define tok_delim " \t\r\n\a"

int RUN = 1;

int main(int argc, char* argv[]) {
	
	if(argc > 1) {
		setuid(atoi(argv[1]));
		setgid(atoi(argv[2]));
	}
	
	sh_loop();

	return 0;

}

void sh_loop() {
	
	char *input;
	char **args;

	do {
		type_prompt();
		input = sh_read_input();
		args = sh_split_input(input);
		exec_instr(args);

		free(input);
		free(args);
	} while (RUN);

}

void type_prompt() {
	printf("$ ");
}

char *sh_read_input() {
	
	int bufSize = input_bufSize;
	int pos = 0;
	char *buffer = malloc(sizeof(char) * bufSize);
	int c;

	if(!buffer) {
		fprintf(stderr, "input buffer allocation error\n");
		exit(EXIT_FAILURE);
	}

	while(1){
		c = getchar();

		if(c == EOF || c == '\n') {
			buffer[pos] = '\0';
			return buffer;
		}else {
			buffer[pos] = c;
		}
		pos++;

		if(pos >= bufSize) {
			bufSize += input_bufSize;
			buffer = realloc(buffer, bufSize);
			if(!buffer) {
				fprintf(stderr, "input buffer allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}

char** sh_split_input(char* input) {

	int bufSize = tok_bufSize;
	int pos = 0;
	char** tokens = malloc(sizeof(char*) * bufSize);
	char *token;

	if(!tokens) {
		fprintf(stderr, "tokens buffer allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(input, tok_delim);
	while(token != NULL) {
		tokens[pos++] = token;

		if(pos >= bufSize) {
			bufSize += tok_bufSize;
			tokens = realloc(tokens, sizeof(char*) * bufSize);
			if(!tokens) {
				fprintf(stderr, "tokens buffer allocation error\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, tok_delim);
	}

	tokens[pos] = NULL;
	return tokens;
}

void exec_instr(char** args){

	if(!strcmp(args[0], "exit")) {
		printf("GoodBye!\n");
		RUN = 0;	
	}
	else if(!strcmp(args[0], "cat")) {
		cat(args[1]);
	}
	else if(!strcmp(args[0], "cd")) {
		cd(args[1]);
	}
	else if(!strcmp(args[0], "chmod")) {
		sh_chmod(args[1], args[2]);
	}
	else if(!strcmp(args[0], "echo")) {
		echo(args[1], args[2]);
	}
	else if(!strcmp(args[0], "find")) {
		find(args[1]);
	}
	else if(!strcmp(args[0], "help")) {
		help();
	}
	else if(!strcmp(args[0], "id")) {
		id();
	}
	else if(!strcmp(args[0], "mkdir")) {
		sh_mkdir(args[1]);
	}
	else if(!strcmp(args[0], "pwd")) {
		pwd();
	}
	else if(!strcmp(args[0], "rm")) {
		rm(args[1]);
	}
	else if(!strcmp(args[0], "rmdir")) {
		sh_rmdir(args[1]);
	}
	else if(!strcmp(args[0], "stat")) {
		sh_stat(args[1]);
	}
	else if(!strcmp(args[0], "touch")) {
		touch(args[1]);
	}
	else if(!strcmp(args[0], "umask")) {
		sh_umask(args[1]);
	}else {
		printf("%s: command not found. type \'help\' to get command list\n", args[0]);
	}

}
