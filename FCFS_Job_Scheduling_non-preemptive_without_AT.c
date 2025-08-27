#include <stdio.h>
int main()
{
    int i, n, bt[15], ct[15], tat[15], wt[15], rt[15], start[15];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst times of the processes: ");
    for (i = 0; i < n; i++)
        scanf("%d", &bt[i]);

    ct[0] = bt[0];

    for (i = 1; i < n; i++)
    {
        start[i] = ct[i - 1];
        ct[i] = start[i] + bt[i];
    }

    float totalTAT = 0, totalWT = 0, totalRT = 0;
    for (i = 0; i < n; i++)
    {
        tat[i] = ct[i];
        wt[i] = tat[i] - bt[i];
        rt[i] = start[i];

        totalTAT += tat[i];
        totalWT += wt[i];
        totalRT += rt[i];
    }

    printf("\tP.No.\tBT\tCT\tTAT\tWT\tRT\n");

    for (i = 0; i < n; i++)
    {
        printf("\t%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, bt[i], ct[i], tat[i], wt[i], rt[i]);
    }

    printf("Average Turn Around Time: %.2f\n", totalTAT / n);
    printf("Average Waiting Time: %.2f\n", totalWT / n);
    printf("Average Response Time: %.2f\n", totalRT / n);

    return 0;
}
