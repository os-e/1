// // i. Process Control:
// // - `fork` is a system call that creates a new child process that is identical to the parent process. It returns the process ID (PID) of the child process to the parent, and 0 to the child. For example, you can write a C program that uses fork to create a new process and print its PID:

// #include <stdio.h>
// #include <unistd.h>

// int main() {
//     int pid = fork(); // create a new process
//     if (pid == 0) { // child process
//         printf("I am the child process. My PID is %d\n", getpid());
//     }
//     else if (pid > 0) { // parent process
//         printf("I am the parent process. My PID is %d and my child's PID is %d\n", getpid(), pid);
//     }
//     else { // fork failed
//         perror("fork");
//     }
//     return 0;
// }


// - `getpid` is a system call that returns the PID of the calling process. You can use it to get the current process's PID, or pass it as an argument to other commands. For example, you can use `ps -p $(getpid)` to display information about the current process.

// - `ps` is a command that displays information about the processes running on the system. You can use various options to customize the output, such as `-a` to show all processes, `-u` to show the user name, `-x` to show processes not attached to a terminal, etc. For example, you can use `ps aux` to show a detailed list of all processes.

// - `kill` is a command that sends a signal to a process to terminate it. You can use the PID of the process as an argument, or use the `-l` option to list the available signals. For example, you can use `kill -9 1234` to send the SIGKILL signal to the process with PID 1234, which will force it to exit.

// - `sleep` is a command that pauses the execution of the current process for a specified number of seconds. You can use it to delay the execution of other commands, or to create background processes that run periodically. For example, you can use `sleep 10 && echo "Hello"` to print "Hello" after 10 seconds.

// ii. Communication:
// - Input-output redirection is a feature that allows you to redirect the standard input, output, or error of a command to a file or another command. You can use the symbols `<`, `>`, and `>>` to perform redirection. For example, you can use `cat < input.txt` to read the contents of input.txt and display them on the screen, or use `ls > output.txt` to save the output of ls to output.txt, or use `echo "Error" >> error.log` to append the string "Error" to error.log.

// - Pipe is a feature that allows you to connect the output of one command to the input of another command. You can use the symbol `|` to create a pipe. For example, you can use `ls | wc -l` to count the number of files in the current directory, or use `ps aux | grep bash` to filter the processes that contain the word "bash".

// iii. Protection Management:
// - `chmod` is a command that changes the permissions of files or directories. You can use either symbolic or numeric notation to specify the permissions. For example, you can use `chmod u+x file.sh` to add the execute permission for the user to file.sh, or use `chmod 755 file.sh` to set the permissions to rwxr-xr-x for file.sh.

// - `chown` is a command that changes the owner of files or directories. You can use either the user name or the user ID as an argument. For example, you can use `chown alice file.txt` to change the owner of file.txt to alice, or use `chown 1000 file.txt` to change the owner to the user with ID 1000.

// - `chgrp` is a command that changes the group of files or directories. You can use either the group name or the group ID as an argument. For example, you can use `chgrp staff file.txt` to change the group of file.txt to staff, or use `chgrp 100 file.txt` to change the group to the group with ID 100.

