#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int coeff;
    int pow;
    Node *next;

    Node(int c, int p)
    {
        coeff = c;
        pow = p;
        next = NULL;
    }
};
class Poly
{
private:
    Node *head;

public:
    Poly()
    {
        head = NULL;
    }
    void append(int c, int e)
    {
        Node *temp = new Node(c,e);
        Node *trav = head;
       
        if (trav->next == NULL)
        {
            head = temp;
            temp->next = head;
            
            return;
        }
       temp->next=temp;
        temp->next->next = trav;
        
    }

    void input()
    {
        int c, e;
        cout << "Enter the polynomial." << endl;
        while (true)
        {
            cout << "Enter the coff:";
            cin >> c;
            cout << "Enter the exp:";
            cin >> e;
            if (e == 0 && c == 0)
                break;
            append(c, e);
            if (e == 0)
                break;
        }
    }

    // Node *ins_end(Node *first, int coeff, int pow)
    // {

    //     Node *temp = new Node(coeff, pow);
    //     Node *curr;
    //     if (!first)
    //     {
    //         first = temp;
    //         temp->next = first;
    //     }
    //     else
    //     {
    //         for (curr = first; curr->next != first; curr = curr->next)
    //             ;
    //         curr->next = temp;
    //         temp->next = first;
    //     }
    //     return first;
    // }

    Node *addp(Node *cur1, Node *cur2)
    {
        if (cur1 == NULL && cur2 == NULL)
        {
            return NULL;
        }

        if (cur1->pow > cur2->pow)
        {

            Node *temp = new Node(cur1->coeff, cur1->pow);

            temp->next = addp(cur1->next, cur2);
        }
        else if (cur1->pow < cur2->pow)
        {

            Node *temp = new Node(cur2->coeff, cur2->pow);

            temp->next = addp(cur1, cur2->next);
        }
        else
        {

            Node *temp = new Node((cur1->coeff + cur2->coeff), cur2->pow);

            temp->next = addp(cur1->next, cur2->next);
        }
    }
    void add3(Poly p1, Poly p2)
    {
        head = addp(p1.head, p2.head);
        return;
    }
    void display()
    {
        Node *trav = new Node(0, 0);
        trav = head;
        if (trav->next == head)
        {
            if (trav->pow == 0)
                cout << trav->coeff << endl;
            else
                cout << trav->coeff << "x^" << trav->pow << endl;
            return;
        }
        do
        {
            cout << trav->coeff << "x^" << trav->pow << " + ";
            trav = trav->next;
        } while (trav->next != head);
        cout << trav->coeff;
        cout << endl;
    }
};

/* The below method print the required sum of polynomial
p1 and p2 as specified in output  */
// Node *addPolynomial(Node *p1, Node *p2)
// {
//     Node *temp = NULL;
//     temp = addp(p1, p2);
//     return temp;
// }

int main()
{

    Poly P1, P2, P3;
    P1.input();
    P2.input();
    // P3.add3(P1, P2);
    cout << "Polynomial 1:";
    P1.display();
    cout << "Polynomial 2:";
    P2.display();
    cout << "Polynomial 3:";
    // P3.display();
    return 0;
}