#include <bits/stdc++.h>

using namespace std;

struct node
{
    int value;
    node *next;
};

class LL
{
private:
    node *head;

public:
    LL()
    {
        head = NULL;
    }

    void append (int ele)
    {
        node *temp = new node;
        temp->value = ele;
        temp->next = head;
        head = temp;
    }

    void insert_after (int ele, int val)
    {
        node *temp = new node;
        temp->value = ele;
        node *t = head;
        int flag = 0;
        while (t != NULL)
        {
            if (t->value == val)
            {
                temp->next = t->next;
                t->next = temp;
                flag++;
                break;
            }
            t = t->next;
        }
        if (flag == 0)
        {
            cout << "Element not found!\n";
        }
    }

    void insert_before (int ele, int val)
    {
        node *temp = new node;
        temp->value = ele;
        node *t = head;
        int flag = 0;
        if (t->value == val)
        {
            head = temp;
            temp->next = t;
            return;
        }
        while (t->next != NULL)
        {
            if (t->next->value == val)
            {
                temp->next = t->next;
                t->next = temp;
                flag++;
                break;
            }
            t = t->next;
        }
        if (flag == 0)
        {
            cout << "Element not found!\n";
        }
    }

    void remove (int ele)
    {
        node *t = head;
        int flag = 0;
        if (t->value == ele)
        {
            head = t->next;
            return;
        }
        while (t->next != NULL)
        {
            if (t->next->value == ele)
            {
                t->next = t->next->next;
                flag++;
                break;
            }
            t = t->next;
        }
        if (t->next == NULL)
        {
            delete t->next;
            t->next = NULL;
            flag++;
        }

        if (flag == 0)
        {
            cout << "Element not found!\n";
        }
    }

    void traverse()
    {
        node *t = new node;
        t = head;
        while (t != NULL)
        {
            cout << t->value << ' ';
            t = t->next;
        }
        cout << '\n';
    }

    void reverse()
    {
        node *prev = NULL, *next = NULL, *curr = head;
        while(curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void sort (bool rev=false)
    {
        // By selection sort
        node *t = head, *t2, *min;
        int temp;
        while(t)
        {
            min = t;
            t2 = t->next;
            while(t2){
                if(t2->value < min->value)
                    min = t2;
                t2 = t2->next;
            }
            if(min != t)
                swap(min->value,t->value);
            t = t->next;
        }
    if(rev)
        reverse();
    }

    void delete_alternate()
    {
        node *temp = head;
        node *temp2 = temp->next;
        while(temp && temp2)
        {
            temp->next = temp2->next;
            delete temp2;
            temp = temp->next;
            if(temp)
                temp2 = temp->next;
        }

    }

    void insert_sort_desc(int elem)
    {
        node *temp = new node;
        node *trav = head;
        temp->value = elem;
        //EDGE CASE:List Empty
        if(head == NULL)
        {
            append(elem);
            return;
        }

        // Insertion by look ahead technique

        // EDGE CASE:Element at head
        if(trav->value < elem)
        {
            temp->next = head;
            head = temp;
            return;
        }
        while(trav->next != NULL)
        {
            if(trav->next->value < elem)
            {
                temp->next = trav->next;
                trav->next = temp;
                break;
            }
            trav = trav->next;
        }
        // EDGE CASE: Element at tail
        if(trav->next == NULL)
        {
            trav->next = temp;
            temp->next = NULL;
        }
    }

    void insert_sort_asc(int elem)
    {
        node *temp = new node;
        temp->value = elem;
        node *trav = head;
        //EDGE CASE:List Empty
        if(head == NULL)
        {
            append(elem);
            return;
        }

        // Insertion by look ahead technique

        // EDGE CASE:Element at head
        if(trav->value > elem)
        {
            temp->next = head;
            head = temp;
            return;
        }
        while(trav->next != NULL)
        {
            if(trav->next->value > elem)
            {
                temp->next = trav->next;
                trav->next = temp;
                break;
            }
            trav = trav->next;
        }
        // EDGE CASE: Element at tail
        if(trav->next == NULL)
        {
            trav->next = temp;
            temp->next = NULL;
        }
    }
};

int main()
{
    LL L;
    int choice;
    int loc,elem;
    L.append(100);
    L.append(200);
    L.append(300);
    L.append(1000);
    cout << "the following operations can be performed on the linked list\n";
    cout << "1.insert before another element\n";
    cout << "2.insert after another element\n";
    cout << "3.delete an element\n";
    cout << "4.traverse the list\n";
    cout << "5.reverse the list\n";
    cout << "6.sort the list\n";
    cout << "7.delete alternate elements\n";
    cout << "8.insert in an order\n";
    cout << "9.exit\n";
    while(true){
        cout << '>';
        cin >> choice;
        switch (choice)
        {
            case 1:
                cout << "enter the element to insert before:";
                cin >> loc;
                cout << "enter the element to insert:";
                cin >> elem;
                L.insert_before(elem, loc);
                break;
            case 2:
                cout << "enter the element to insert after:";
                cin >> loc;
                cout << "enter the element to insert:";
                cin >> elem;
                L.insert_after(elem, loc);
                break;
            case 3:
                cout << "enter the element to delete:";
                cin >> elem;
                L.remove(elem);
                break;
            case 4:
                L.traverse();
                break;
            case 5:
                L.reverse();
                break;
            case 6:
                cout << "0 for Ascending\n1 for Descending\n";
                cout << '>';
                cin >> elem;
                L.sort(elem);
                break;
            case 7:
                L.delete_alternate();
                break;
            case 8:
                int order;
                cout << "enter the element to insert and 0 for ascending and 1 for descending:";
                cin >> elem;
                cin >> order;
                switch (order)
                {
                    case 0: L.insert_sort_asc(elem);
                            break;
                    case 1: L.insert_sort_desc(elem);
                            break;
                }
                break;
            case 9:
                return 0;
            default:
                cout << "Invalid Choice!\n";
        }
    }
}
