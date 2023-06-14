#include <iostream>
using namespace std;

struct process
{
public:
    int pid;
    int at;//arrival time
    int bt;//burst time
    int ct;//completion time
    int wt;//waiting time
    int tat;//turn arond time
    int rt;//response time = waiting time
    int start_t;//start time for process 
};
void sortA(process *p, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].at > p[j + 1].at)
            {
                int temp = p[j].at;
                p[j].at = p[j + 1].at;
                p[j + 1].at = temp;
                temp = p[j].bt;
                p[j].bt = p[j + 1].bt;
                p[j + 1].bt = temp;
                temp = p[j].pid;
                p[j].pid = p[j + 1].pid;
                p[j + 1].pid = temp;
            }
        }
    }
}
int main()
{
    cout << "Enter the no of process";
    int n;

    cin >> n;
    process p[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter process ID " << i << " - arrival time";
        cin >> p[i].at;
       
        p[i].pid = i;
    }
    for (int i = 0; i < n; i++)
    {
         cout << "Enter process ID " << i << " - burst time";
        cin >> p[i].bt;
       
        p[i].pid = i;
    }
    sortA(p, n);

    int sum_tat=0,sum_wt=0,sum_rt=0;
    for (int i = 0 ; i < n; i++)
    {
        // if (p[i].at > p[i - 1].ct)
        // {
        //     p[i].ct = p[i].at + p[i].bt;
        // }
        // else
        // {
        //     p[i].ct = p[i - 1].ct + p[i].bt;
        // }

        p[i].start_t=(i==0)? p[i].at:max(p[i].at,p[i-1].ct);
        p[i].ct = p[i].start_t + p[i].bt;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        p[i].rt=p[i].wt;
        sum_tat+=p[i].tat;
        sum_wt+=p[i].wt;
        sum_rt+=p[i].rt;
    }
    
    cout<< "PID\tAT\tBT\tCT\tTAT\tWT\tRT\n";
    for (int i = 0; i < n; i++)
    {
        cout << p[i].pid << "\t" << p[i].at << "\t" << p[i].bt << "\t" << p[i].ct << "\t" << p[i].tat << "\t" << p[i].wt << "\t" << p[i].rt << endl;
    }
    cout<<"Average TAT: "<<sum_tat/n<<endl;
    cout<<"Average WT: "<<sum_wt/n<<endl;
    cout<<"Average RT: "<<sum_rt/n<<endl;
    int length_cycle=p[n-1].ct-p[0].at;
    cout<<"Throughput= "<<n/length_cycle<<endl;
    int total_ideal=0;
    for(int i=0;i<n;i++){
        total_ideal+=(i==0) ? 0:(p[i].start_t-p[i-1].ct);
    }
    cout<<"Ideal time = "<<total_ideal<<endl;
    cout<<"CPU Utilisation= "<<((length_cycle-total_ideal)/length_cycle)*100;
    return 0;
}