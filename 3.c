1.
#include <stdio.h>
#include <unistd.h>

int main() {
    int pid = fork(); // create a new process
    if (pid == 0) { // child process
        printf("I am the child process. My PID is %d\n", getpid());
    }
    else if (pid > 0) { // parent process
        printf("I am the parent process. My PID is %d and my child's PID is %d\n", getpid(), pid);
    }
    else { // fork failed
        perror("fork");
    }
    return 0;
}


ps -p $(getpid)

ps aux

kill -9 1234

sleep 10 && echo "Hello"

2.
  
cat < input.txt
ls > output.txt
echo "Error" >> error.log

ls | wc -l
ps aux | grep bash

3.

chmod u+x file.sh
chmod 755 file.sh

chown alice file.txt
chown 1000 file.txt

chgrp staff file.txt
chgrp 100 file.txt

