#include <iostream>
#include <string.h>
using namespace std;
#define qsize 100
class pqueue
{
    int front, rear;
    char username[100], task_name[100];
    int task_size;
    int hr, min, sec;

public:
    pqueue()
    {
        front = rear = -1;
    }
    void enqueue(pqueue a[], char u[], char t[], int h, int mi, int se, int p)
    {

        {
            strcpy(a[++rear].username, u);
            rear--;
            strcpy(a[++rear].task_name, t);
            rear--;
            a[++rear].hr = h;
            rear--;
            a[++rear].min = mi;
            rear--;
            a[++rear].sec = se;
            rear--;
            a[++rear].task_size = p;
        }
    }
    void display(pqueue a[])
    {
        for (int i = 0; i <= rear; i++)
        {
            cout << a[i].username << " ";
        }
    }
    bool time(pqueue a[], int i)
    {
        if (a[i].hr < a[front].hr)
            return true;
        else if (a[i].hr = a[front].hr)
        {
            if (a[i].min < a[front].min)
                return true;
            else if (a[i].min = a[front].min)
              { 
                   if (a[i].sec < a[front].sec)
                       return true;
              }
        }
        return false;
    }
    int peek(pqueue a[])
    {
        int highestpr = -1;

        for (int i = 0; i <= rear; i++)
        {
            if (a[i].task_size > highestpr)
            {
                highestpr = a[i].task_size;
                front = i;
            }
            else if (highestpr == a[i].task_size && front > -1 && time(a, i))
            {
                highestpr = a[i].task_size;
                front = i;
            }
        }
        return front;
    }
    void dequeue(pqueue a[])
    {
        if (rear == -1)
            cout << "queue undeflow";
        else
        {
            int front = peek(a);
            cout << "deleted ele is:" << a[front].username << endl;
            for (int i = front; i <= rear; i++)
            {
                a[i] = a[i + 1];
            }
            rear--;
        }
    }
};
int main()
{
    pqueue ob, q[100];
    int option, ele, prior;
    cout << "Choose your option\n";
    do
    {
        cout << endl;
        cout << "1.Insert\n2.Delete\n3.display\n4.exit\n";
        cin >> option;
        cin.ignore();
        switch (option)
        {
        case 1:
        {
            int hr, min, sec;
            char user[100], task[100], arrival[100], ch = ':';
            cout << "enter the username to be pushed\n";
            cin.getline(user, 100);
            cout << "enter the taskname to be pushed\n";
            cin.getline(task, 100);
            cout << "enter the arrival time to be pushed\n";
            cin >> hr >> ch >> min >> ch >> sec;
            cout << "enter the element task_size to be pushed\n";
            cin >> prior;
            ob.enqueue(q, user, task, hr, min, sec, prior);
        }
        break;
        case 2:
        {
            ob.dequeue(q);
        }
        break;
        case 3:
        {
            ob.display(q);
        }
        break;
        default:
            exit(0);
        }
    } while (option < 4);
}
