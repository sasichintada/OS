#include <stdio.h>

int main() {
    int bt[10], wt[10], p[10], i, k, n, temp;
    float wavg = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        p[i] = i;
        printf("Enter burst time %d: ", i);
        scanf("%d", &bt[i]);
    }

    // Sorting burst times and process IDs using SJF (ascending order)
    for (i = 0; i < n; i++) {
        for (k = i + 1; k < n; k++) {
            if (bt[i] > bt[k]) {
                // Swap burst times
                temp = bt[i];
                bt[i] = bt[k];
                bt[k] = temp;

                // Swap process IDs
                temp = p[i];
                p[i] = p[k];
                p[k] = temp;
            }
        }
    }

    wt[0] = 0;
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        wavg += wt[i];
    }

    printf("\nProcess\tBurst Time\tWaiting Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i]);
    }

    printf("Average waiting time = %.6f\n", wavg / n);
    return 0;
}
