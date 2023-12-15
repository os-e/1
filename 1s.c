// // #include<stdio.h>
// // #include<unistd.h>
// // #include<stdlib.h>
// // #include<sys/wait.h>
// // #include<sys/types.h>

// // #define PRINT(...) fprintf(stdout, __VA_ARGS__)
// // #define QUIT exit(1)

// // void sameProgramSameCode(){
// //     system("clear");
// //     PRINT("Now parent and child will execute same code and print pid of themselves and then exit\n");
// //     fork();
// //     PRINT("pid: %d\n",getpid());
// //     QUIT;
// // }
// // void sameProgramDifferentCode(){
// //     PRINT("Now we will execute different code in parent and child\n");
// //     pid_t pid = fork();
// //     pid==0 ? (PRINT("Inside child with pid: %d\n",getpid()), QUIT) : pid>0 ? (PRINT("Inside parent with pid: %d\n",getpid()), QUIT) : (PRINT("ERROR: while forking"), QUIT);
// // }
// // void sameProgramWaitForChildToExit(){
// //     PRINT("Now we will execute different code in parent and child and parent will wait for child\n");
// //     pid_t pid = fork();
// //     pid==0 ? (sleep(1), PRINT("Inside child with pid: %d\n",getpid()), PRINT("Exiting child\n"), QUIT) : pid>0 ? (PRINT("Inside parent with pid: %d\n",getpid()), PRINT("Parent waiting for child\n"), wait(NULL), PRINT("Exiting parent\n"), QUIT) : (PRINT("ERROR: while forking"), QUIT);
// // }
// // int main()
// // {
// //     int choice;
// //     while(1)
// //     {
// //         PRINT("1) Same program and same code\n");
// //         PRINT("2) Same program different code\n");
// //         PRINT("3) before terminating the parent wait for the child to finish it's task\n");
// //         PRINT("Enter 0 to exit...\n");
// //         scanf("%d",&choice);
// //         switch(choice){
// //             case 0:
// //                 QUIT;
// //             case 1:
// //                 sameProgramSameCode();
// //                 break;
// //             case 2:
// //                 sameProgramDifferentCode();
// //                 break;
// //             case 3:
// //                 sameProgramWaitForChildToExit();
// //                 break;
// //             default:
// //                 PRINT("ERROR: wrong choice try again...\n");
// //         }
// //     }
// //     return 0;
// // }

// // 5 question

// // #include <stdio.h>
// // #include <stdlib.h>

// // int main() {
// //     printf("\nKernel Version:\n");
// //     system("cat /proc/version");

// //     printf("\nCPU Type and Model:\n");
// //     system("cat /proc/cpuinfo | grep 'processor\\|model'");
    
// //     return 0;
// // }

// // 6 question

// #include <stdio.h>
// #include <stdlib.h>

// int main() {
//     printf("\nKernel Version:\n");
//     system("cat /proc/version");

//     printf("\nInformation on Configured amount of free and used Memory:\n");
//     system("cat /proc/meminfo | awk '/Mem/ {print}'");
//     return 0;
// }
// // 7 question

// #include <unistd.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <fcntl.h>
// #include <sys/stat.h>

// #define BUFFER_SIZE 1024
// void copy(char *src, char *dst){
//     int sfd, dfd, count;
//     char buffer[BUFFER_SIZE];
//     mode_t fileMode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

//     if ((sfd = open(src, O_RDONLY)) < 0){
//         fprintf(stderr, "ERROR: %s doesn't exist or cannot be opened for reading\n", src);
//         exit(1);
//     }
//     dfd = open(dst, O_CREAT | O_WRONLY | O_TRUNC, fileMode);
//     while ((count = read(sfd, buffer, BUFFER_SIZE)) > 0)
//         write(dfd, buffer, count);
//     close(sfd);
//     close(dfd);
// }

// int main(int argc, char *argv[]){
//     if (argc != 3){
//         fprintf(stderr, "ERROR: usage: %s <src> <dst>\n", argv[0]);
//         return 1;
//     }
//     printf("Copying %s to %s\n", argv[1], argv[2]);
//     copy(argv[1], argv[2]);
//     return 0;
// }
// // 8 question

// #include <stdio.h>
// struct Process { int pid, arrival_time, burst_time; };
// void fcfs_scheduling(struct Process p[], int n) {
//     int w[n], t[n], tw = 0, tt = 0;
//     w[0] = 0;
//     t[0] = p[0].burst_time;

//     for (int i = 1; i < n; i++) {
//         w[i] = (t[i - 1] > p[i].arrival_time) ? t[i - 1] - p[i].arrival_time : 0;
//         t[i] = w[i] + p[i].burst_time;
//         tw += w[i];
//         tt += t[i];
//     }
//     printf("Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
//     for (int i = 0; i < n; i++)
//         printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, w[i], t[i]);
//     printf("Average Waiting Time: %.2f\nAverage Turnaround Time: %.2f\n", (float)tw / n, (float)tt / n);
// }

// int main() {
//     int n;
//     printf("Enter the number of processes: ");
//     scanf("%d", &n);
//     struct Process p[n];
//     printf("Enter arrival and burst time for the processes:\n");
//     for (int i = 0; i < n; i++) {
//         p[i].pid = i + 1;
//         printf("Process %d - Arrival Time: ", i + 1);
//         scanf("%d", &p[i].arrival_time);
//         printf("Process %d - Burst Time: ", i + 1);
//         scanf("%d", &p[i].burst_time);
//     }
//     fcfs_scheduling(p, n);
//     return 0;
// }
// // 9 question

// #include <stdio.h>
// struct Process { int pid, burst_time; };
// void sjf_scheduling(struct Process p[], int n) {
//     int w[n], t[n], tw = 0, tt = 0;
//     w[0] = 0;
//     t[0] = p[0].burst_time;

//     for (int i = 1; i < n; i++) {
//         w[i] = t[i - 1];
//         t[i] = w[i] + p[i].burst_time;
//         tw += w[i];
//         tt += t[i];
//     }
//     printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
//     for (int i = 0; i < n; i++)
//         printf("%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burst_time, w[i], t[i]);
//     printf("Average Waiting Time: %.2f\nAverage Turnaround Time: %.2f\n", (float)tw / n, (float)tt / n);
// }

// int main() {
//     int n;
//     printf("Enter the number of processes: ");
//     scanf("%d", &n);
//     struct Process p[n];
//     printf("Enter burst time for the processes:\n");
//     for (int i = 0; i < n; i++) {
//         p[i].pid = i + 1;
//         printf("Process %d: ", i + 1);
//         scanf("%d", &p[i].burst_time);
//     }
//     sjf_scheduling(p, n);
//     return 0;
// }

// // 10 question

// #include <stdio.h>
// struct Process { int pid, burst_time, priority; };
// void priority_scheduling(struct Process p[], int n) {
//     int w[n], t[n], tw = 0, tt = 0;
//     for (int i = 0; i < n; i++) {
//         for (int j = i + 1; j < n; j++) {
//             if (p[i].priority > p[j].priority) {
//                 struct Process temp = p[i];
//                 p[i] = p[j];
//                 p[j] = temp;
//             }
//         }
//     }
//     w[0] = 0;
//     t[0] = p[0].burst_time;
//     for (int i = 1; i < n; i++) {
//         w[i] = t[i - 1];
//         t[i] = w[i] + p[i].burst_time;
//         tw += w[i];
//         tt += t[i];
//     }
//     printf("Process\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
//     for (int i = 0; i < n; i++)
//         printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burst_time, p[i].priority, w[i], t[i]);
//     printf("Average Waiting Time: %.2f\nAverage Turnaround Time: %.2f\n", (float)tw / n, (float)tt / n);
// }

// int main() {
//     int n;
//     printf("Enter the number of processes: ");
//     scanf("%d", &n);
//     struct Process p[n];
//     printf("Enter burst time and priority for the processes:\n");
//     for (int i = 0; i < n; i++) {
//         p[i].pid = i + 1;
//         printf("Process %d - Burst Time: ", i + 1);
//         scanf("%d", &p[i].burst_time);
//         printf("Process %d - Priority: ", i + 1);
//         scanf("%d", &p[i].priority);
//     }
//     priority_scheduling(p, n);
//     return 0;
// }
// // 11 question

// #include<pthread.h>
// #include<stdio.h>
// #include<stdlib.h>
// int sum;
// void *runner(void *param);
// int main(int argc,char *argv[]){
//     pthread_t tid;
//     if(argc!=2 || atoi(argv[1])<0){
//         fprintf(stderr,"usage:a.out<integervalue>\n%d must be >= 0\n",atoi(argv[1]));
//         return -1;
//     }
//     pthread_create(&tid,NULL,runner,argv[1]);
//     pthread_join(tid,NULL);
//     printf("SUM = %d\n",sum);
//     return 0;
// }
// void *runner(void *param){
//     int i,upper = atoi(param);
//     sum = 0;
//     for(i = 1;i <= upper; i++)
//         sum+=i;
//     pthread_exit(0);
// }

// // 12 question

// #include<stdio.h>
// void allocate(int b[], int m, int p[], int n, int c) {
//     int a[n], i, j, bi, wi;
//     int ifrag = 0, efrag = 0;
//     for (i = 0; i < n; i++) {
//         a[i] = -1;
//     }
//     for (i = 0; i < n; i++) {
//         switch(c) {
//             case 1: // First Fit
//                 for (j = 0; j < m; j++) {
//                     if (b[j] >= p[i]) {
//                         a[i] = j;
//                         b[j] -= p[i];
//                         break;
//                     }
//                 }
//                 break;
//             case 2: // Best Fit
//                 bi = -1;
//                 for (j = 0; j < m; j++) {
//                     if (b[j] >= p[i]) {
//                         if (bi == -1 || b[bi] > b[j]) {
//                             bi = j;
//                         }
//                     }
//                 }
//                 if (bi != -1) {
//                     a[i] = bi;
//                     b[bi] -= p[i];
//                 }
//                 break;
//             case 3: // Worst Fit
//                 wi = -1;
//                 for (j = 0; j < m; j++) {
//                     if (b[j] >= p[i]) {
//                         if (wi == -1 || b[wi] < b[j]) {
//                             wi = j;
//                         }
//                     }
//                 }
//                 if (wi != -1) {
//                     a[i] = wi;
//                     b[wi] -= p[i];
//                 }
//                 break;
//         }
//     }
//     printf("\nProcess No.\tProcess Size\tBlock no.\n");
//     for (i = 0; i < n; i++) {
//         printf("%d\t\t%d\t\t", i+1, p[i]);
//         if (a[i] != -1) {
//             printf("%d\n", a[i] + 1);
//             ifrag += b[a[i]];
//         } else {
//             printf("Not Allocated\n");
//         }
//     }
//     for (i = 0; i < m; i++) {
//         if (b[i] > 0) {
//             efrag += b[i];
//         }
//     }
//     printf("\nInternal Fragmentation = %d", ifrag);
//     printf("\nExternal Fragmentation = %d\n", efrag);
// }

// int main() {
//     int b[10], p[10], m, n, i, c;
//     printf("Enter the number of blocks: ");
//     scanf("%d", &m);
//     printf("Enter the size of each block: \n");
//     for(i = 0; i < m; i++) {
//         printf("Block[%d]: ", i+1);
//         scanf("%d", &b[i]);
//     }
//     printf("Enter the number of processes: ");
//     scanf("%d", &n);
//     printf("Enter the size of each process: \n");
//     for(i = 0; i < n; i++) {
//         printf("Process[%d]: ", i+1);
//         scanf("%d", &p[i]);
//     }
//     printf("Choose the allocation strategy:\n1. First Fit\n2. Best Fit\n3. Worst Fit\n");
//     scanf("%d", &c);
//     allocate(b, m, p, n, c);
//     return 0;
// }
