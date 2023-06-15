#include <stdio.h>
#define max 100

void main() {
    int i, j, n, bt[max], wt[max], tat[max];
    float awt = 0, atat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst time of the processes: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }

    printf("\n");
    printf("Process\tBurst time\tWaiting time\tTurnaround time\n\n");

    for (i = 0; i < n; i++) {
        wt[i] = 0;
        tat[i] = 0;

        for (j = 0; j < i; j++) {
            wt[i] = wt[i] + bt[i];
        }

        tat[i] = wt[i] + bt[i];

        awt = awt + wt[i];
        atat = atat + tat[i];

        printf("%d\t%d\t\t%d\t\t%d\n\n", i + 1, bt[i], wt[i], tat[i]);
    }

    awt = awt / n;
    atat = atat / n;

    printf("Average waiting time = %f\n\n", awt);
    printf("Average turnaround time = %f\n", atat);
}

/**************** OUTPUT *************************** 
   Enter the number of processes: 4
   Enter the burst time of the processes: 4 10 6 8

   Process     Burst time    Waiting time    Turnaround time

   1           4             0               4

   2           10            10              20

   3           6             12              18

   4           8             24              32

   Average waiting time = 11.500000
   Average turnaround time = 18.500000
*/