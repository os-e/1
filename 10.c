#include <stdio.h>
struct Process { int pid, burst_time, priority; };
void priority_scheduling(struct Process p[], int n) {
    int w[n], t[n], tw = 0, tt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].priority > p[j].priority) {
                struct Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    w[0] = 0;
    t[0] = p[0].burst_time;
    for (int i = 1; i < n; i++) {
        w[i] = t[i - 1];
        t[i] = w[i] + p[i].burst_time;
        tw += w[i];
        tt += t[i];
    }
    printf("Process\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burst_time, p[i].priority, w[i], t[i]);
    printf("Average Waiting Time: %.2f\nAverage Turnaround Time: %.2f\n", (float)tw / n, (float)tt / n);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process p[n];
    printf("Enter burst time and priority for the processes:\n");
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Process %d - Burst Time: ", i + 1);
        scanf("%d", &p[i].burst_time);
        printf("Process %d - Priority: ", i + 1);
        scanf("%d", &p[i].priority);
    }
    priority_scheduling(p, n);
    return 0;
}
