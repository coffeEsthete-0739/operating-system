#include<stdio.h>
int main()
{
    int i,n;
    printf("Enter the number of process:");
    scanf("%d",&n);
    int pid[20],bt[20],priority[20],ct[20],tat[20],wt[20],completed[20]= {0};

    for(i=0; i<n; i++)
    {
        pid[i]=i+1;
        printf("Enter burst time and priority for process %d:",i+1);
        scanf("%d %d",&bt[i],&priority[i]);
    }
    int time=0,count=0;
    float avgtat=0,avgwt=0;
    while(count<n)
    {
        int idx=-1;
        int bestpriority=99999;
        for(i=0; i<n; i++)
        {
            if(!completed[i])
            {
                if(priority[i]<bestpriority)
                {
                    bestpriority=priority[i];
                    idx=i;
                }
                else if(priority[i]==bestpriority)
                {
                    if(pid[i]<pid[idx]){
                        idx=i;
                    }
                }
            }
        }
    time += bt[idx];
    ct[idx]=time;
    tat[idx]=ct[idx];
    wt[idx]=tat[idx]-bt[idx];
    completed[idx]=1;
    count++;
    }

    printf("PID\tBT\tPRIORITY\tCT\tTAT\tWT\n");
    for(i=0; i<n ;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",pid[i],bt[i],priority[i],ct[i],tat[i],wt[i]);
        avgtat+=tat[i];
        avgwt+=wt[i];
    }
    printf("Average TAT = %.2f\n",avgtat/n);
    printf("Average WT = %.2f\n",avgwt/n);

    return 0;

}

