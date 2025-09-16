#include <iostream>
using namespace std;

int main()
{
    int n, bt[15], priority[15], ct[15], wt[15], tat[15], st[15];
    int done[15] = {0}, currentTime = 0, completed = 0;

    cout << "Enter the number of processes: ";
    cin >> n;

    cout << "Enter the burst times: ";
    for (int i = 0; i < n; i++)
        cin >> bt[i];

    cout << "Enter the priority values: "; // Lower the number = Higher the priority
    for (int i = 0; i < n; i++)
        cin >> priority[i];

    while (completed < n)
    {
        int bestPriority = -1;
        for (int i = 0; i < n; i++)
        {
            if (!done[i])
            {
                if (bestPriority = -1 || priority[i] < priority[bestPriority])
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
    cout << "P.No.\tBT\tPr\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "\t" << bt[i] << "\t" << priority[i] << "\t" << ct[i] << "\t" << tat[i] << "\t" << wt[i]
             << endl;

        totalWT += wt[i];
        totalTAT += tat[i];
    }
    cout << "Average Turn Around Time: " << totalTAT / n << endl;
    cout << "Average Waiting Time: " << totalWT / n << endl;

    return 0;
}
