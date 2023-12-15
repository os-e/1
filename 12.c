#include<stdio.h>
void allocate(int b[], int m, int p[], int n, int c) {
    int a[n], i, j, bi, wi;
    int ifrag = 0, efrag = 0;
    for (i = 0; i < n; i++) {
        a[i] = -1;
    }
    for (i = 0; i < n; i++) {
        switch(c) {
            case 1: // First Fit
                for (j = 0; j < m; j++) {
                    if (b[j] >= p[i]) {
                        a[i] = j;
                        b[j] -= p[i];
                        break;
                    }
                }
                break;
            case 2: // Best Fit
                bi = -1;
                for (j = 0; j < m; j++) {
                    if (b[j] >= p[i]) {
                        if (bi == -1 || b[bi] > b[j]) {
                            bi = j;
                        }
                    }
                }
                if (bi != -1) {
                    a[i] = bi;
                    b[bi] -= p[i];
                }
                break;
            case 3: // Worst Fit
                wi = -1;
                for (j = 0; j < m; j++) {
                    if (b[j] >= p[i]) {
                        if (wi == -1 || b[wi] < b[j]) {
                            wi = j;
                        }
                    }
                }
                if (wi != -1) {
                    a[i] = wi;
                    b[wi] -= p[i];
                }
                break;
        }
    }
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i+1, p[i]);
        if (a[i] != -1) {
            printf("%d\n", a[i] + 1);
            ifrag += b[a[i]];
        } else {
            printf("Not Allocated\n");
        }
    }
    for (i = 0; i < m; i++) {
        if (b[i] > 0) {
            efrag += b[i];
        }
    }
    printf("\nInternal Fragmentation = %d", ifrag);
    printf("\nExternal Fragmentation = %d\n", efrag);
}

int main() {
    int b[10], p[10], m, n, i, c;
    printf("Enter the number of blocks: ");
    scanf("%d", &m);
    printf("Enter the size of each block: \n");
    for(i = 0; i < m; i++) {
        printf("Block[%d]: ", i+1);
        scanf("%d", &b[i]);
    }
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the size of each process: \n");
    for(i = 0; i < n; i++) {
        printf("Process[%d]: ", i+1);
        scanf("%d", &p[i]);
    }
    printf("Choose the allocation strategy:\n1. First Fit\n2. Best Fit\n3. Worst Fit\n");
    scanf("%d", &c);
    allocate(b, m, p, n, c);
    return 0;
}
