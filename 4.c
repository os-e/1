#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>

#define PRINT(...) fprintf(stdout, __VA_ARGS__)
#define QUIT exit(1)

void sameProgramSameCode(){
    system("clear");
    PRINT("Now parent and child will execute same code and print pid of themselves and then exit\n");
    fork();
    PRINT("pid: %d\n",getpid());
    QUIT;
}
void sameProgramDifferentCode(){
    PRINT("Now we will execute different code in parent and child\n");
    pid_t pid = fork();
    pid==0 ? (PRINT("Inside child with pid: %d\n",getpid()), QUIT) : pid>0 ? (PRINT("Inside parent with pid: %d\n",getpid()), QUIT) : (PRINT("ERROR: while forking"), QUIT);
}
void sameProgramWaitForChildToExit(){
    PRINT("Now we will execute different code in parent and child and parent will wait for child\n");
    pid_t pid = fork();
    pid==0 ? (sleep(1), PRINT("Inside child with pid: %d\n",getpid()), PRINT("Exiting child\n"), QUIT) : pid>0 ? (PRINT("Inside parent with pid: %d\n",getpid()), PRINT("Parent waiting for child\n"), wait(NULL), PRINT("Exiting parent\n"), QUIT) : (PRINT("ERROR: while forking"), QUIT);
}
int main()
{
    int choice;
    while(1)
    {
        PRINT("1) Same program and same code\n");
        PRINT("2) Same program different code\n");
        PRINT("3) before terminating the parent wait for the child to finish it's task\n");
        PRINT("Enter 0 to exit...\n");
        scanf("%d",&choice);
        switch(choice){
            case 0:
                QUIT;
            case 1:
                sameProgramSameCode();
                break;
            case 2:
                sameProgramDifferentCode();
                break;
            case 3:
                sameProgramWaitForChildToExit();
                break;
            default:
                PRINT("ERROR: wrong choice try again...\n");
        }
    }
    return 0;
}
