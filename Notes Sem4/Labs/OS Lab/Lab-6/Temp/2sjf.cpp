#include <iostream>
using namespace std;
struct process
{
public:
    int pid;
    int at;      // arrival time
    int bt;      // burst time
    int ct;      // completion time
    int wt;      // waiting time
    int tat;     // turn arond time
    int rt;      // response time = waiting time
    int start_t; // start time for process
};
void sjf(process *p,int n){
    int completed=0;
    
    int current_time=0;
    while(completed!=n){

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
    sjf(p,n);
    int sum_tat = 0, sum_wt = 0, sum_rt = 0;
    
    

    return 0;
}