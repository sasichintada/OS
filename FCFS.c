#include <stdio.h>

int main() {
    int bt[10], wt[10], i, n;
    float wavg = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i);
        scanf("%d", &bt[i]);
    }

    wt[0] = 0;
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        wavg += wt[i];
    }

    printf("\nProcess\tBurst Time\tWaiting Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\n", i, bt[i], wt[i]);
    }

    printf("Average waiting time: %.6f\n", wavg / n);
    return 0;
}
