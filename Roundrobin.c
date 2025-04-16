#include <stdio.h>

int main() 
{
    int i, n, time_quantum, remaining_processes, time = 0;
    int burst_time[10], waiting_time[10], turnaround_time[10], remaining_time[10];
    float total_waiting_time = 0, total_turnaround_time = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    remaining_processes = n;

    for(i = 0; i < n; i++) 
    {
        printf("Enter Burst Time for process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
        remaining_time[i] = burst_time[i]; // Copy burst time to remaining_time
    }

    printf("Enter the size of time slice (Time Quantum): ");
    scanf("%d", &time_quantum);

    // Processing using Round Robin Algorithm
    while(remaining_processes > 0) 
    {
        for(i = 0; i < n; i++) 
        {
            if (remaining_time[i] > 0) 
            {
                if (remaining_time[i] <= time_quantum) 
                {
                    time += remaining_time[i]; // Process completes
                    turnaround_time[i] = time; // Completion time recorded
                    waiting_time[i] = turnaround_time[i] - burst_time[i]; // Calculate waiting time
                    remaining_time[i] = 0; // Mark as completed
                    remaining_processes--; // Reduce count of remaining processes
                } 
                else 
                {
                    time += time_quantum; // Execute for time quantum
                    remaining_time[i] -= time_quantum; // Reduce remaining burst time
                }
            }
        }
    }

    // Calculate total turnaround time and waiting time
    for(i = 0; i < n; i++) 
    {
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }

    // Display results
    printf("\nThe Average Turnaround Time is: %.2f", total_turnaround_time / n);
    printf("\nThe Average Waiting Time is: %.2f", total_waiting_time / n);
    printf("\n\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    
    for(i = 0; i < n; i++) 
    {
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, burst_time[i], waiting_time[i], turnaround_time[i]);
    }

    return 0;
}

Enter the no of processes – 3
Enter Burst Time for process 1 – 24
Enter Burst Time for process 2 -- 3
Enter Burst Time for process 3 -- 3
Enter the size of time slice – 3
OUTPUT:
The Average Turnaround time is – 15.666667
The Average Waiting time is -- 5.666667
PROCESS BURST TIME WAITING TIME TURNAROUND TIME
p1 24 6 30
p2 3 4 7
p3 3 7 10
