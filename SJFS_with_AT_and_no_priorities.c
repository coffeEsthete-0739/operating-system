#include <stdio.h>

int main()
{
    int n, at[15], bt[15], ct[15], tat[15], wt[15], rt[15], st[15], done[15] = {0}, currentTime = 0, completed = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the arrival times of the processes: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &at[i]);

    printf("Enter the burst times of the processes: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &bt[i]);

    while (completed < n)
    {
        int p = -1;
        for (int i = 0; i < n; i++)
        {
            if (!done[i] && at[i] <= currentTime)
            {
                if (p == -1 || bt[i] < bt[p])
                {
                    p = i;
                }
            }
        }

        if (p == -1)
        {
            currentTime++;
        }
        else
        {
            st[p] = currentTime;
            ct[p] = st[p] + bt[p];
            tat[p] = ct[p] - at[p];
            wt[p] = tat[p] - bt[p];
            rt[p] = st[p] - at[p];

            done[p] = 1;
            completed++;
            currentTime = ct[p];
        }
    }

    float totalTAT = 0, totalWT = 0, totalRT = 0;
    for (int i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        rt[i] = st[i] - at[i];

        totalTAT += tat[i];
        totalWT += wt[i];
        totalRT += rt[i];
    }

    printf("\tP.No.\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++)
    {
        printf("\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i], rt[i]);
    }

    printf("Average Turn Around Time: %.2f\n", totalTAT / n);
    printf("Average Waiting Time: %.2f\n", totalWT / n);
    printf("Average Response Time: %.2f\n", totalRT / n);

    return 0;
}
