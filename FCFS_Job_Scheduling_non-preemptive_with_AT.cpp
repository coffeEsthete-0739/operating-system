#include <iostream>
using namespace std;

int main()
{
    int n, at[15], bt[15], ct[15], tat[15], wt[15], rt[15], start[15];

    cout << "Enter the number of processes: ";
    cin >> n;

    cout << "Enter the arrival times of the processes: ";
    for (int i = 0; i < n; i++)
        cin >> at[i];

    cout << "Enter the burst times of the processes: ";
    for (int i = 0; i < n; i++)
        cin >> bt[i];

    start[0] = at[0];
    ct[0] = at[0] + bt[0];

    for (int i = 1; i < n; i++)
    {
        if (at[i] > ct[i - 1])
            start[i] = at[i];
        else
            start[i] = ct[i - 1];

        ct[i] = start[i] + bt[i];
    }

    float totalTAT = 0, totalWT = 0, totalRT = 0;
    for (int i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        rt[i] = start[i] - at[i];

        totalTAT += tat[i];
        totalWT += wt[i];
        totalRT += rt[i];
    }

    cout << "\tP.No.\tAT\tBT\tCT\tTAT\tWT\tRT\n";
    for (int i = 0; i < n; i++)
    {
        cout << "\t" << i + 1 << "\t" << at[i] << "\t" << bt[i] << "\t" << ct[i] << "\t" << tat[i] << "\t" << wt[i] << "\t"
             << rt[i] << "\n";
    }

    cout << "Average Turn Around Time: " << totalTAT / n << endl;
    cout << "Average Waiting Time: " << totalWT / n << endl;
    cout << "Average Response Time: " << totalRT / n << endl;

    return 0;
}
