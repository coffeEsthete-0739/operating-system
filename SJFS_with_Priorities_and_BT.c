#include <stdio.h>

int main()
{
    int n, bt[15], priority[15], ct[15], wt[15], tat[15], st[15];
    int done[15] = {0}, currentTime = 0, completed = 0;


    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst times: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &bt[i]);

    printf("Enter the priority values: "); // Lower the number = Higher the priority
    for (int i = 0; i < n; i++)
        scanf("%d", &priority[i]);

    while (completed < n)
    {
        int bestPriority = -1;
        for (int i = 0; i < n; i++)
        {
            if (!done[i])
            {
                if (bestPriority == -1 || priority[i] < priority[bestPriority])
                {
                    bestPriority = i;
                }
            }
        }
        st[bestPriority] = currentTime;
        ct[bestPriority] = st[bestPriority] + bt[bestPriority];
        tat[bestPriority] = ct[bestPriority];
        wt[bestPriority] = tat[bestPriority] - bt[bestPriority];

        done[bestPriority] = 1;
        completed++;
        currentTime = ct[bestPriority];
    }

    float totalWT = 0, totalTAT = 0;

    printf("P.No.\tBT\tPr\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, bt[i], priority[i], ct[i], tat[i], wt[i]);

        totalWT += wt[i];
        totalTAT += tat[i];
    }
    printf("Average Turn Around Time: %.2f\n", totalTAT / n);
    printf("Average Waiting Time: %.2f\n", totalWT / n);

    return 0;
}
