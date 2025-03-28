#include <stdio.h>

int main() {
    int p[20], bt[20], pri[20], wt[20], i, k, n, temp;
    float wavg;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        p[i] = i;
        printf("Enter the burst time & priority of process %d: ", i);
        scanf("%d%d", &bt[i], &pri[i]);
    }

    // Sorting processes based on priority (lower number = higher priority)
    for (i = 0; i < n; i++) {
        for (k = i + 1; k < n; k++) {
            if (pri[i] > pri[k]) {
                // Swap priority
                temp = pri[i];
                pri[i] = pri[k];
                pri[k] = temp;

                // Swap burst time
                temp = bt[i];
                bt[i] = bt[k];
                bt[k] = temp;

                // Swap process number
                temp = p[i];
                p[i] = p[k];
                p[k] = temp;
            }
        }
    }

    wt[0] = wavg = 0;

    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        wavg += wt[i];
    }

    printf("\nProcess\tPriority\tBurst Time\tWaiting Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t\t%d\t\t%d\n", p[i], pri[i], bt[i], wt[i]);
    }

    printf("\nAverage waiting time is %f\n", wavg / n);
    return 0;
}
