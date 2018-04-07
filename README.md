Secure Interactive Shell
===
by Tzu-Hsuan Tseng

## How to use 
Just `make` to compile and `./siShell` to launch the shell program. </br> When you see the prompt like `$ `, you can type in command.

## Commands
| Command | Description |
| :------ | :---------- |
| cat {file} | Display content of {file}. (file ONLY, not directory) </br> If the {file} doesn't exist, output "cat: {file}: No such file". |
| cd {dir} | Switch current working directory to {dir}. </br> Output "current working directory: {dir}". </br> If the {dir} doesn't exist, output "cd: {dir}: No such file or directory". |
| chmod {mode} {file/dir} | Change the mode (permission) of a file or directory. </br> {mode} must be a valid octal number. </br> Output "change '{file/dir}' permission to {mode} successfully". </br> If failed, output "change '{file/dir}' permission to {mode} failed". |
| echo {str} | Display {str}. |
| echo {str} {filename} | Open {filename} and append {str} to the file. </br> If the {filename} doesn't exist, output "can't append {str} to file {filename}, file doesn't exist". |
| exit | Leave the shell. </br> Output "GoodBye!". |
| find | List files/dirs in the current working directory. |
| find {dir} | List files/dirs in the {dir}. </br> Outputs contatin file name, type, and size. </br> If the {dir} doesn't exist, output "cannot open directory {dir}". |
| help | Display help message. </br> Output commands, parameters, and descriptions. |
| id | Show current euid and egid number. </br>  Output "euid = geteuid() , egid = getegid()". |
| mkdir {dir} | Create a new directory {dir}. </br> Output "new directory - {dir} has been created". |
| pwd | Print the current working directory. |
| rm {file} | Remove a file. </br> Output "file - {file} has been removed". </br> If failed, output "remove file - {file} failed". |
| rmdir {dir} | Remove an empty directory. </br> Output "remove an empty directory - {dir} successfully". </br> If failed, output "remove an empty directory - {dir} failed". |
| stat {file/dir} | Display detailed information of the given file/dir. </br> Outputs contain file name, type, size, blocks, io block, device, inode, links, access, uid, gid, last access time, last modify time, and last change time. </br> If the {file/dir} doesn't exist, output "stat: cannot stat '{file/dir}': No such file or directory". |
| touch {file} | Update the {file}'s access and modification timestamp. </br> Output "touch file '{file}' successfully". </br> If {file} does not exist, create empty file named {file}. </br> Output "create file '{file}' successfully because it does not exist previously". |
| umask {mode} | Change the umask of the current session. </br> {mode} must be a valid octal number. </br> Output "the umask value is {mode} now". |

If there are some missing parameters, output "usage: {command} {parameter 1} [parameter 2]".</br>If command not recognized, output "{command}: command not found. type 'help' to get command list".


