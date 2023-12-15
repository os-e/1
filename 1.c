// // question 4
// #include<stdio.h>
// #include<unistd.h>
// #include<stdlib.h>
// #include<sys/wait.h>
// #include<sys/types.h>

// void sameProgramSameCode(){
//     system("clear");
//     fprintf(stdout,"Now parent and child will execute same code and print pid of themselves and then exit\n");
//     fork();
//     fprintf(stdout,"pid: %d\n",getpid());
//     exit(1);
// }
// void sameProgramDifferentCode(){
//     fprintf(stdout,"Now we will execute different code in parent and child\n");
//     pid_t pid = fork();
//     if(pid==0)
//     {
//         fprintf(stdout,"Inside child with pid: %d\n",getpid());
//         exit(1);
//     }
//     else if(pid>0)
//     {
//         fprintf(stdout,"Inside parent with pid: %d\n",getpid());
//         exit(1);
//     }
//     else
//     {
//         fprintf(stderr,"ERROR: while forking");
//         exit(1);
//     }
// }
// void sameProgramWaitForChildToExit(){
//     fprintf(stdout,"Now we will execute different code in parent and child and parent will wait for child\n");
//     pid_t pid = fork();
//     if(pid==0)
//     {
//         sleep(1);
//         fprintf(stdout,"Inside child with pid: %d\n",getpid());
//         fprintf(stdout,"Exiting child\n");
//         exit(1);
//     }
//     else if(pid>0)
//     {
//         fprintf(stdout,"Inside parent with pid: %d\n",getpid());
//         fprintf(stdout,"Parent waiting for child\n");
//         wait(NULL);
//         fprintf(stdout,"Exiting parent\n");
//         exit(1);
//     }
//     else
//     {
//         fprintf(stderr,"ERROR: while forking");
//         exit(1);
//     }
// }
// int main()
// {
//     int choice;
//     while(1)
//     {
//         printf("1) Same program and same code\n");
//         printf("2) Same program different code\n");
//         printf("3) before terminating the parent wait for the child to finish it's task\n");
//         printf("Enter 0 to exit...\n");
//         scanf("%d",&choice);
//         switch(choice){
//             case 0:
//                 exit(0);
//             case 1:
//                 sameProgramSameCode();
//                 break;
//             case 2:
//                 sameProgramDifferentCode();
//                 break;
//             case 3:
//                 sameProgramWaitForChildToExit();
//                 break;
//             default:
//                 printf("ERROR: wrong choice try again...\n");
//         }
//     }
//     return 0;
// }
// // question 5
// #include <stdio.h>
// #include <stdlib.h>

// int main() {
//     printf("\nKernel Version:\n");
//     system("cat /proc/version");

//     printf("\nCPU Type and Model:\n");
//     system("cat /proc/cpuinfo | grep 'processor\\|model'");
    
//     return 0;
// }
// // question 6
// #include <stdio.h>
// #include <stdlib.h>

// int main() {
//     printf("\nKernel Version:\n");
//     system("cat /proc/version");

//     printf("\nInformation on Configured amount of free and used Memory:\n");
//     system("cat /proc/meminfo | awk '/Mem/ {print}'");
//     return 0;
// }
// // question 7
// #include <unistd.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <sys/types.h>
// #include <sys/wait.h>
// #include <fcntl.h>
// #define BUFFER_SIZE 1024
// void copy(char *, char *);
// int main(int argc, char *argv[])
// {
//     if (argc != 3){
//         fprintf(stderr, "ERROR: usage: %s <src> <dst>\n", argv[0]);
//         return 1;
//     }
//     printf("Copying %s to %s\n", argv[1], argv[2]);
//     copy(argv[1], argv[2]);
//     return 0;
// }

// void copy(char *src, char *dst){
//     int sfd, dfd, count;
//     char buffer[BUFFER_SIZE];
//     mode_t fileMode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

//     sfd = open(src, O_RDONLY);
//     if (sfd < 0){
//         fprintf(stderr, "ERROR: %s doesn't exist or cannot be opened for reading\n", src);
//         exit(1);
//     }
//     dfd = open(dst, O_CREAT | O_WRONLY | O_TRUNC, fileMode);
//     while ((count = read(sfd, buffer, BUFFER_SIZE)) > 0){
//         write(dfd, buffer, count);
//     }
//     close(sfd);
//     close(dfd);
// }
// // question 8
// #include <stdio.h>
// struct Process {
//     int pid; // Process ID
//     int arrival_time; // Arrival time
//     int burst_time; // Burst time
// };
// void fcfs_scheduling(struct Process processes[], int n) {  //processes as p[]
//     int waiting_time[n], turnaround_time[n];  //or 1st line int w[n],t[n],tw=0,tt=0;
//     int total_waiting_time = 0, total_turnaround_time = 0; //or 2nd line w[0]=0,t[0]=p[0].burst_time'   
//     waiting_time[0] = 0;
//     turnaround_time[0] = processes[0].burst_time;

//     for (int i = 1; i < n; i++) {       // then here
//         waiting_time[i] = (turnaround_time[i - 1] > processes[i].arrival_time) ? turnaround_time[i - 1] - processes[i].arrival_time : 0;
//         turnaround_time[i] = waiting_time[i] + processes[i].burst_time;
//     }
//     for (int i = 0; i < n; i++) {
//         total_waiting_time += waiting_time[i];
//         total_turnaround_time += turnaround_time[i];
//     }
//     printf("Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
//     for (int i = 0; i < n; i++) {
//         printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, waiting_time[i], turnaround_time[i]);
//     }
//     printf("Average Waiting Time: %.2f\n", (float)total_waiting_time / n);
//     printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / n);
// }

// int main() {
//     int n;
//     printf("Enter the number of processes: ");
//     scanf("%d", &n);
//     struct Process processes[n]; //processes as p[n]
//     printf("Enter arrival and burst time for the processes:\n");
//     for (int i = 0; i < n; i++) {
//         processes[i].pid = i + 1;
//         printf("Process %d - Arrival Time: ", i + 1);
//         scanf("%d", &processes[i].arrival_time);
//         printf("Process %d - Burst Time: ", i + 1);
//         scanf("%d", &processes[i].burst_time);
//     }
//     fcfs_scheduling(processes, n);
//     return 0;
// }
// // question 9 
// #include <stdio.h>

// // Structure to represent a process
// struct Process {
//     int pid; // Process ID
//     int burst_time; // Burst time
// };

// // Function to perform SJF scheduling
// void sjf_scheduling(struct Process processes[], int n) {
//     int waiting_time[n], turnaround_time[n];
//     int total_waiting_time = 0, total_turnaround_time = 0;

//     // Calculate waiting time and turnaround time for each process
//     waiting_time[0] = 0;
//     turnaround_time[0] = processes[0].burst_time;

//     for (int i = 1; i < n; i++) {
//         waiting_time[i] = turnaround_time[i - 1];
//         turnaround_time[i] = waiting_time[i] + processes[i].burst_time;
//     }

//     // Calculate total waiting time and turnaround time
//     for (int i = 0; i < n; i++) {
//         total_waiting_time += waiting_time[i];
//         total_turnaround_time += turnaround_time[i];
//     }

//     // Print the schedule
//     printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
//     for (int i = 0; i < n; i++) {
//         printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, waiting_time[i], turnaround_time[i]);
//     }

//     // Calculate and print the average waiting time and turnaround time
//     printf("Average Waiting Time: %.2f\n", (float)total_waiting_time / n);
//     printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / n);
// }

// int main() {
//     int n;

//     // Input: Number of processes
//     printf("Enter the number of processes: ");
//     scanf("%d", &n);

//     struct Process processes[n];
//     printf("Enter burst time for the processes:\n");
//     // Input: Burst times for each process
//     for (int i = 0; i < n; i++) {
//         processes[i].pid = i + 1;
//         printf("Process %d: ", i + 1);
//         scanf("%d", &processes[i].burst_time);
//     }

//     // Perform SJF scheduling and display results
//     sjf_scheduling(processes, n);

//     return 0;
// }

// // question 10
// #include <stdio.h>
// struct Process {
//     int pid; // Process ID
//     int burst_time; // Burst time
//     int priority; // Priority
// };
// void priority_scheduling(struct Process processes[], int n) {
//     int waiting_time[n], turnaround_time[n];
//     int total_waiting_time = 0, total_turnaround_time = 0;
//     for (int i = 0; i < n; i++) {
//         for (int j = i + 1; j < n; j++) {
//             if (processes[i].priority > processes[j].priority) {
//                 struct Process temp = processes[i];
//                 processes[i] = processes[j];
//                 processes[j] = temp;
//             }
//         }
//     }
//     waiting_time[0] = 0;
//     turnaround_time[0] = processes[0].burst_time;
//     for (int i = 1; i < n; i++) {
//         waiting_time[i] = turnaround_time[i - 1];
//         turnaround_time[i] = waiting_time[i] + processes[i].burst_time;
//     }
//     for (int i = 0; i < n; i++) {
//         total_waiting_time += waiting_time[i];
//         total_turnaround_time += turnaround_time[i];
//     }
//     printf("Process\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
//     for (int i = 0; i < n; i++) {
//         printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].priority, waiting_time[i], turnaround_time[i]);
//     }
//     printf("Average Waiting Time: %.2f\n", (float)total_waiting_time / n);
//     printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / n);
// }

// int main() {
//     int n;
//     printf("Enter the number of processes: ");
//     scanf("%d", &n);
//     struct Process processes[n];
//     printf("Enter burst time and priority for the processes:\n");
//     for (int i = 0; i < n; i++) {
//         processes[i].pid = i + 1;
//         printf(" burst time for Process %d: ", i + 1);
//         scanf("%d", &processes[i].burst_time);
//         printf(" priority for Process %d: ", i + 1);
//         scanf("%d", &processes[i].priority);
//     }
//     priority_scheduling(processes, n);
//     return 0;
// }
// // question 11
// // program to calculate the sum of n numbers using pthreads
// #include<pthread.h>
// #include<stdio.h>
// #include<stdlib.h>
// int sum;
// void *runner(void *param);
// int main(int argc,char *argv[]){
//     pthread_t tid;
//     pthread_attr_t attr;
//     if(argc!=2){
//         fprintf(stderr,"usage:a.out<integervalue>\n");
//         return -1;
//     }
//     if(atoi(argv[1])<0){
//         fprintf(stderr,"%d must be >= 0\n",atoi(argv[1]));
//         return -1;
//     }
//     pthread_attr_init(&attr);
//     pthread_create(&tid,&attr,runner,argv[1]);
//     pthread_join(tid,NULL);
//     printf("SUM = %d\n",sum);
//     return 0;
// }
// void *runner(void *param){
//     int i,upper = atoi(param);
//     sum = 0;
//     for(i = 1;i <= upper; i++){
//         sum+=i;
//     }
//     pthread_exit(0);
// }
// // question 12
// // program to implement the different allocation strategies.
// #include<stdio.h>
// void allocate(int blockSize[], int m, int processSize[], int n, int choice) {
//     int allocation[n], i, j, bestIdx, wstIdx;
//     int internalFragmentation = 0, externalFragmentation = 0;
//     for (i = 0; i < n; i++) {
//         allocation[i] = -1;
//     }
//     for (i = 0; i < n; i++) {
//         switch(choice) {
//             case 1: // First Fit
//                 for (j = 0; j < m; j++) {
//                     if (blockSize[j] >= processSize[i]) {
//                         allocation[i] = j;
//                         blockSize[j] -= processSize[i];
//                         break;
//                     }
//                 }
//                 break;
//             case 2: // Best Fit
//                 bestIdx = -1;
//                 for (j = 0; j < m; j++) {
//                     if (blockSize[j] >= processSize[i]) {
//                         if (bestIdx == -1) {
//                             bestIdx = j;
//                         } else if (blockSize[bestIdx] > blockSize[j]) {
//                             bestIdx = j;
//                         }
//                     }
//                 }
//                 if (bestIdx != -1) {
//                     allocation[i] = bestIdx;
//                     blockSize[bestIdx] -= processSize[i];
//                 }
//                 break;
//             case 3: // Worst Fit
//                 wstIdx = -1;
//                 for (j = 0; j < m; j++) {
//                     if (blockSize[j] >= processSize[i]) {
//                         if (wstIdx == -1) {
//                             wstIdx = j;
//                         } else if (blockSize[wstIdx] < blockSize[j]) {
//                             wstIdx = j;
//                         }
//                     }
//                 }
//                 if (wstIdx != -1) {
//                     allocation[i] = wstIdx;
//                     blockSize[wstIdx] -= processSize[i];
//                 }
//                 break;
//         }
//     }
//     printf("\nProcess No.\tProcess Size\tBlock no.\n");
//     for (i = 0; i < n; i++) {
//         printf("%d\t\t%d\t\t", i+1, processSize[i]);
//         if (allocation[i] != -1) {
//             printf("%d\n", allocation[i] + 1);
//             internalFragmentation += blockSize[allocation[i]];
//         } else {
//             printf("Not Allocated\n");
//         }
//     }
//     for (i = 0; i < m; i++) {
//         if (blockSize[i] > 0) {
//             externalFragmentation += blockSize[i];
//         }
//     }
//     printf("\nInternal Fragmentation = %d", internalFragmentation);
//     printf("\nExternal Fragmentation = %d\n", externalFragmentation);
// }

// int main() {
//     int blockSize[10], processSize[10], m, n, i, choice;
//     printf("Enter the number of blocks: ");
//     scanf("%d", &m);
//     printf("Enter the size of each block: \n");
//     for(i = 0; i < m; i++) {
//         printf("Block[%d]: ", i+1);
//         scanf("%d", &blockSize[i]);
//     }
//     printf("Enter the number of processes: ");
//     scanf("%d", &n);
//     printf("Enter the size of each process: \n");
//     for(i = 0; i < n; i++) {
//         printf("Process[%d]: ", i+1);
//         scanf("%d", &processSize[i]);
//     }
//     printf("Choose the allocation strategy:\n1. First Fit\n2. Best Fit\n3. Worst Fit\n");
//     scanf("%d", &choice);
//     allocate(blockSize, m, processSize, n, choice);
//     return 0;
// }
