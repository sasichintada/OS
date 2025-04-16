#include<stdio.h>

int main()
{
    int bt[20], wt[20], tat[20], i, n;
    float wtavg, tatavg;

    printf("\nEnter the number of processes -- ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("\nEnter Burst Time for Process %d -- ", i);
        scanf("%d", &bt[i]);
    }

    wt[0] = wtavg = 0;
    tat[0] = tatavg = bt[0];

    for(i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
        wtavg = wtavg + wt[i];
        tatavg = tatavg + tat[i];
    }

    printf("\nPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");

    for(i = 0; i < n; i++)
        printf("P%d\t\t%d\t\t\t%d\t\t\t%d\n", i, bt[i], wt[i], tat[i]);

    printf("\nAverage Waiting Time -- %f", wtavg / n);
    printf("\nAverage Turnaround Time -- %f", tatavg / n);

    return 0;
}
Enter the number of processes -- 3 
Enter Burst Time for Process 0 -- 24
Enter Burst Time for Process 1 -- 3 
Enter Burst Time for Process 2 -- 3 
OUTPUT:
PROCESS BURST TIME WAITING TIME TURNAROUND TIME
P0 24 0 24 
P1 3 24 27 
P2 3 27 30 
Average Waiting Time-- 17.000000 
Average Turnaround Time -- 27.000000
