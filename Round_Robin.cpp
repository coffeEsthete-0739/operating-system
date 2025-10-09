#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, tq;
    cout << "Enter number of process: ";
    cin >> n;

    vector<int> pid(n), at(n), bt(n), rt(n), ct(n), tat(n), wt(n), inqueue(n,0);
    vector<int> q(n*n);

    for (int i = 0; i < n; i++) {
        pid[i] = i+1;
        cout << "Enter arrival time & burst time for p: ";
        cin >> at[i] >> bt[i];
        rt[i] = bt[i];
    }

    cout << "Enter time quantum: ";
    cin >> tq;

    int time=0, completed=0, front=0, rear=-1;
    float avgtat=0, avgwt=0;

    while (1) {
        for (int i=0; i<n; i++) {
            if (at[i] <= time && rt[i] > 0 && !inqueue[i]) {
                q[++rear] = i;
                inqueue[i] = 1;
            }
        }

        if (front > rear) {
            int nextat = 1e9, idx = -1;
            for (int i=0; i<n; i++) {
                if (rt[i] > 0 && at[i] < nextat) {
                    nextat = at[i];
                    idx = i;
                }
            }
            if (idx == -1) break;
            time = nextat;
            q[++rear] = idx;
            inqueue[idx] = 1;
            continue;
        }

        int i = q[front++];
        inqueue[i] = 0;

        if (rt[i] > tq) {
            rt[i] -= tq;
            time += tq;
        } else {
            time += rt[i];
            rt[i] = 0;
            ct[i] = time;
            completed++;
        }

        for (int j=0; j<n; j++) {
            if (at[j] <= time && rt[j] > 0 && !inqueue[j]) {
                q[++rear] = j;
                inqueue[j] = 1;
            }
        }

        if (rt[i] > 0) {
            q[++rear] = i;
            inqueue[i] = 1;
        }

        if (completed == n) break;
    }

    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i=0; i<n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        avgtat += tat[i];
        avgwt += wt[i];
        cout << "p" << pid[i] << "\t" << at[i] << "\t" << bt[i] << "\t"
             << ct[i] << "\t" << tat[i] << "\t" << wt[i] << "\n";
    }

    cout << "\nAverage TAT=" << avgtat/n;
    cout << "\nAverage WT=" << avgwt/n << endl;

    return 0;
}