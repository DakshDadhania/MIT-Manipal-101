#include <iostream>
#include <stdio.h>
using namespace std;
enum task_size
{
    XS,
    S,
    M,
    L,
    XL
};

class Time
{
public:
    int hour;
    int min;
    int sec;
    void read()
    {
        cout << "enter the hour:";
        cin >> hour;
        cout << "enter the minute:";
        cin >> min;
        cout << "enter the second:";
        cin >> sec;
    };
    void display()
    {
        cout << "the time is : " << hour << " hours ," << min << " minutes ," << sec << " seconds" << endl;
    };
};
int compare(Time t1, Time t2)
{
    if (t1.hour > t2.hour)
        return 1;
    else if (t1.hour == t2.hour)
    {
        if (t1.min > t2.min)
            return 1;
        else if (t1.min == t2.min)
        {
            if (t1.sec > t2.sec)
                return 1;
            else if (t1.sec == t2.sec)
                return 0;
            else
                return -1;
        }
        else
            return -1;
    }
    else
        return -1;
}
class Task
{
    string username;
    string taskname;
    task_size ts;
    Time arrival_time;

public:
    bool completed;
    Task(){};
    Task(string un, string tn, task_size t, Time arrt)
    {
        username = un;
        taskname = tn;
        ts = t;
        arrival_time = arrt;
        completed = false;
    };
    void get(Task arr[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            string name;
            string taskname;
            task_size ts;
            Time arrt;
            char ch;
            cout << "enter user name :";
            cin >> name;
            cout << "enter task name :";
            cin >> taskname;
            cout << "enter arrival time :\n";
            arrt.read();
            do
            {
                cout << "enter task size:\na)extra small task \nb)small task \nc)medium task \nd)large task \ne)extra large task\n";
                cin >> ch;

                switch (ch)
                {
                case 'a':
                    ts = XS;
                    break;
                case 'b':
                    ts = S;
                    break;
                case 'c':
                    ts = M;
                    break;
                case 'd':
                    ts = L;
                    break;
                case 'e':
                    ts = XL;
                    break;
                default:
                    cout << "error in input\n";
                }
            } while (ch != 'a' && ch != 'b' && ch != 'c' && ch != 'd' && ch != 'e');
            arr[i] = Task(name, taskname, ts, arrt);
        }
    }
    void complete()
    {
        completed = true;
    }
    Task selecttask(Task arr[], int n)
    {
        int i = 0;
        int pos;
        bool flag = false;
        for (i = 0; i < n; i++)
        {
            if (!(arr[i].completed))
            {
                pos = i;
                flag = true;
                break;
            }
        }
        for (int j = i; j < n - 1; j++)
        {
            if (arr[pos].ts > arr[i + 1].ts)
            {
                if (!(arr[i + 1].completed))
                {
                    pos = i + 1;
                    flag = true;
                }
            }
            else if (arr[pos].ts == arr[i + 1].ts)
            {
                if (!(arr[i + 1].completed) && (compare(arr[pos].arrival_time, arr[i + 1].arrival_time) == 1))
                {
                    pos = i + 1;
                    flag = true;
                }
            }
        }
        if (flag == false)
        {
            cout << "\nall tasks completed!";
            exit(0);
        }
        else
        {
            arr[pos].complete();
        }
        return arr[pos];
    }
    void display()
    {
        cout << "\nuser name:" << username;
        cout << "\nTask name:" << taskname;
        cout << "\ntask size:";
        if (ts == 0)
            cout << "XS";
        else if (ts == 1)
            cout << "S";
        else if (ts == 2)
            cout << "M";
        else if (ts == 3)
            cout << "L";
        else
            cout << "XL";
    }
};
int main()
{
    Task arr[50];
    int n;
    cout << "enter number of tasks :";
    cin >> n;
    Task demo;
    demo.get(arr, n);
    Task curr;
    while (true)
    {
        curr = demo.selecttask(arr, n);
        curr.display();
    }
}
