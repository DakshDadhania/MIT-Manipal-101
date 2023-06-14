#include <iostream>
using namespace std;
class node {
    public:
        int data;
        node* next;
};
node* head=NULL;
void insertfirst(int node_data)
{
    node* newNode=new node;
    newNode->data = node_data;
    newNode->next = head;
    head = newNode;
}
void insertAfter(node* prev_node, int node_data)
{
    node* newNode =new node;
    newNode->data = node_data;
    newNode->next = prev_node->next;
    prev_node->next = newNode;
}
void deleteFirstNode()
{
   node* tempNode = head;
   head = head->next;
   delete tempNode;
}
void removeLastNode()
{
   if (head->next == NULL) {
      delete head;
   }
    node* second_last = head;
    while (second_last->next->next != NULL)
    {second_last = second_last->next;}
    delete (second_last->next);
    second_last->next = NULL;
    }
void delete_node(int n){

    node* tempNode=head;
    int k=n-1;
    while (k!=1){
        tempNode=tempNode->next;
        k--;
    }
    node* temp=tempNode->next;
    tempNode->next=tempNode->next->next;
    delete (temp);
    }
void displayList()
{
   class node* Node=head;
   while (Node!= NULL)
   {
      cout<<Node->data<<"-->";
      Node= Node->next;
   }

    if(Node== NULL)
        cout<<"null";
}
int main()
{
    cout<<"Enter \n 1. Insert at first position. \n 2. Insert at nth node \n 3. Delete last node \n 4. Delete first node \n 5. Delete nth element \n 6. Display \n 0. Exit loop.";
    int flag=1,d;
    while (flag !=0){
        cout<<"\n Enter flag:";
        cin>>flag;
        if (flag==1)
        {
            cout<<"Enter Data:";
            cin>>d;
            insertfirst(d);
        }
        else if (flag==2)
        {
            int pos;
            cout<<"Enter Data and position:";
            cin>>d;
            cin>>pos;
            struct node* t=head;
            for (int i=0;i<pos-2;i++){
                t=t->next;
            }
            insertAfter(t,d);}
        else if (flag==4)
        {
            deleteFirstNode();
        }
        else if (flag==3)
        {
            removeLastNode();
        }
        else if (flag==5)
        {
            int pos;
            cin>>pos;
            delete_node(pos);
        }
        else if (flag==6)
        {
            displayList();
        }
        cout<<"\n "<<flag;
    }
    return 0;
}
