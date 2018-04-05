#include <stdio.h>

void help() {
	
	printf("%-25s%s\n", "cat {file}:", "Display content of {file}.");
	printf("%-25s%s\n", "cd {dir}:", "Switch current working directory to {dir}.");
	printf("%-25s%s\n", "chmod {mode} {file/dir}:", "Change the mode (permission) of a file or directory.");
	printf("%-25s%s\n", "", "{mode} is an octal number.");
	printf("%-25s%s\n", "echo {str} [filename]:", "Display {str}. If [filename] is given,");
	printf("%-25s%s\n", "", "open [filename] and append {str} to the file.");
	printf("%-25s%s\n", "exit:", "Leave the shell.");
	printf("%-25s%s\n", "find [dir]:", "List files/dirs in the current working directory");
	printf("%-25s%s\n", "", "or [dir] if it is given.");
	printf("%-25s%s\n", "help:", "Display help message.");
	printf("%-25s%s\n", "id:", "Show current euid and egid number.");
	printf("%-25s%s\n", "mkdir {dir}:", "Create a new directory {dir}.");
	printf("%-25s%s\n", "pwd:", "Print the current working directory.");
	printf("%-25s%s\n", "rm {file}:", "Remove a file.");
	printf("%-25s%s\n", "rmdir {dir}:", "Remove an empty directory.");
	printf("%-25s%s\n", "stat {file/dir}:", "Display detailed information of the given file/dir.");
	printf("%-25s%s\n", "touch {file}:", "Create {file} if it does not exist,");
	printf("%-25s%s\n", "", "or update its access and modification timestamp.");
	printf("%-25s%s\n", "umask {mode}:", "Change the umask of the current session.");
	return;
}
