#include <iostream>

using namespace std;
const int max_size = 30;
class queue
{
    int front = -1, rear = -1;
    int q[max_size];

public:
    void insert(int item)
    {
        if (((rear + 1) % max_size) == front)
        { // is full
            cout << "Queue Full  \n";
            return;
        }
        if (front == -1 && rear == -1) // is empty
            front++;
        rear = (rear + 1) % max_size;
        q[rear] = item;
    }
    int del()
    {
        if (front == -1 && rear == -1) // is empty
        {
            cout << "Empty queue"
                 << "\n";
            return -1;
        }
        int elem = q[front];
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % max_size;
        }
        return elem;
    }
    void display()
    {
        int i;
        for (i = front; i != rear; i = (i + 1) % max_size)
        {
            cout << q[i] << ' ';
        }
        cout << q[i] << endl;
    }
    queue()
    {
        front = -1;
        rear = -1;
    }
};
int main()
{
    queue cq;
    cout << "1.Insert" << endl;
    cout << "2.Delete" << endl;
    cout << "3.Display" << endl;
    cout << "4.Quit" << endl;
    int choice, item;
    do
    {

        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Input the element for insertion in queue : ";
            cin >> item;
            cq.insert(item);
            break;
        case 2:
            cout << cq.del() << " deleted";
            break;
        case 3:
            cq.display();
            break;
        case 4:
            break;
        default:
            cout << "Wrong choice" << endl;
        }
    } while (choice != 4);
    return 0;
}
