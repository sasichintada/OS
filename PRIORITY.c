#include<stdio.h>

int main()
{
    int p[20], bt[20], pri[20], wt[20], tat[20], i, k, n, temp;
    float wtavg, tatavg;

    printf("Enter the number of processes --- ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        p[i] = i;
        printf("Enter the Burst Time & Priority of Process %d --- ", i);
        scanf("%d %d", &bt[i], &pri[i]);
    }

    // Sort based on Priority (lower number = higher priority)
    for(i = 0; i < n; i++)
    {
        for(k = i + 1; k < n; k++)
        {
            if(pri[i] > pri[k])
            {
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

    wt[0] = wtavg = 0;
    tat[0] = tatavg = bt[0];

    for(i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
        wtavg = wtavg + wt[i];
        tatavg = tatavg + tat[i];
    }

    printf("\nPROCESS\tPRIORITY\tBURST TIME\tWAITING TIME\tTURNAROUND TIME");
    for(i = 0; i < n; i++)
    {
        printf("\nP%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t%d", p[i], pri[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time is --- %f", wtavg / n);
    printf("\nAverage Turnaround Time is --- %f\n", tatavg / n);

    return 0;
}

Enter the number of processes -- 5 
Enter the Burst Time & Priority of Process 0 --- 10 3 
Enter the Burst Time & Priority of Process 1 --- 1 1 
Enter the Burst Time & Priority of Process 2 --- 2 4 
Enter the Burst Time & Priority of Process 3 --- 1 5 
Enter the Burst Time & Priority of Process 4 --- 5 2
OUTPUT :
PROCESS PRIORITY BURST TIME WAITING TIME TURNAROUND TIME
p1 1 1 0 1 
p4 2 5 1 6 
p0 3 10 6 16 
p2 4 2 16 18 
p3 5 1 18 19 
Average Waiting Time is --- 8.200000 
Average Turnaround Time is --- 12.000000
