#include <iostream>
#define max_size 40
using namespace std;

class queue
{
    int front, rear;
    int q[max_size];

public:
    void insert(int item)
    {
        if (rear == max_size - 1)
        {
            cout << "Queue Overflow  \n";
            return;
        }
        rear += 1;
        q[rear] = item;
    }
    int frontele()
    {
        if (front > rear)
            return -99;
        return q[front];
    }
    int size()
    {
        if (!isEmpty())
        {
            return ((rear - front) + 1);
        }
        return 0;
    }
    int del()
    {
        if (front > rear)
            return -99;
        return q[front++];
    }
    void display()
    {
        int i;
        if (front > rear)
        {
            cout << "Empty array\n";
            return;
        }

        for (int i = front; i <= rear; i++)
        {
            cout << q[i] << " ";
        }
    }
    bool isEmpty()
    {
        if (front > rear)
        {
            return true;
        }
        return false;
    }
    bool isFull()
    {
        if (rear == max_size - 1)
        {
            return true;
        }
        return false;
    }
    queue()
    {
        front = 0;
        rear = -1;
    }
};
class Stack
{

    queue q1, q2;

public:
    void push(int x)
    {

        q2.insert(x);

        while (!q1.isEmpty())
        {
            q2.insert(q1.frontele());
            q1.del();
        }

        queue q = q1;
        q1 = q2;
        q2 = q;
    }

    int pop()
    {
        if (q1.isEmpty())
            return -999;
        return q1.del();
    }

    int top()
    {
        if (q1.isEmpty())
            return -1;
        return q1.frontele();
    }

    int size()
    {
        return q1.size();
    }
    int display()
    {

        q1.display();
    }
};
int main()
{
    Stack s1;
    cout << "1.Pop   2.Push   3.Display  0.Exit\n";
    int choice;
    cin >> choice;

    do
    {
        switch (choice)
        {
        case 1:
            cout << "\nPoped " << s1.pop() << '\n';
            break;
        case 2:
            cout << "Enter element to push ";
            int ele;
            cin >> ele;
            s1.push(ele);
            break;
        case 3:
            s1.display();
            break;
        }
        cout << "Enter Choice again? :\n";
        cout << "1.Pop   2.Push   3.Display  0.Exit\n";
        cin >> choice;
    } while (choice != 0);
    // s1.push(1);
    // s1.push(2);
    // s1.push(3);
    // cout<<" "<<s1.pop();
    // s1.display();
    // s1.push(4);
    // s1.display();
    return 0;
}

// OUTPUT
//  32 1 4 2 1