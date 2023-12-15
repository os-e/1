#include <stdio.h>
struct Process { int pid, arrival_time, burst_time; };
void fcfs_scheduling(struct Process p[], int n) {
    int w[n], t[n], tw = 0, tt = 0;
    w[0] = 0;
    t[0] = p[0].burst_time;

    for (int i = 1; i < n; i++) {
        w[i] = (t[i - 1] > p[i].arrival_time) ? t[i - 1] - p[i].arrival_time : 0;
        t[i] = w[i] + p[i].burst_time;
        tw += w[i];
        tt += t[i];
    }
    printf("Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, w[i], t[i]);
    printf("Average Waiting Time: %.2f\nAverage Turnaround Time: %.2f\n", (float)tw / n, (float)tt / n);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process p[n];
    printf("Enter arrival and burst time for the processes:\n");
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Process %d - Arrival Time: ", i + 1);
        scanf("%d", &p[i].arrival_time);
        printf("Process %d - Burst Time: ", i + 1);
        scanf("%d", &p[i].burst_time);
    }
    fcfs_scheduling(p, n);
    return 0;
}
