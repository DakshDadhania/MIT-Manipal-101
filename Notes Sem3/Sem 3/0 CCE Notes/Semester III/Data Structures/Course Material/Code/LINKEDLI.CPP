#include<iostream>
#include<stdlib.h>

using namespace std;
class node
{
    int a;
    int info;
    node *next;
   public:

  node();
  void insert_beg();
  void ins_end();
  void print();
  void del_beg();
  void ins();
  void del();
  void ins_sort();
  void insbegNOtail();
  void insendNOtail();
  void del_alternate();
}*head, *tail;
node::node()
{

}

void node::ins()
{
 node *temp=new node;
 node *t,*t1;
 cout<<"Enter the value to be inserted \n";
 cin>>temp->info;
 temp->next=NULL;
 cout<<"Enter the position:\n";
 int pos;
 cin>>pos;
 if(head==NULL)
 {
  head=temp;
 }
 else
 {
  t=head;
  for(int i=1;i<pos-1;i++)
     t=t->next;
  t1=t->next;
  t->next=temp;
  temp->next=t1;
 }
}

void node::insbegNOtail()
{
 node *temp=new node;
 cout<<"Enter the value:";
 cin>>temp->info;
 temp->next=NULL;
 if(head==NULL)
 {
     head=temp;
 }
 else
    {
     temp->next=head;
     head=temp;
    }
}

void node::insendNOtail()
{
 node *temp=new node, *cur;
 cout<<"Enter the value:";
 cin>>temp->info;
 temp->next=NULL;
 cur = head;
 if(head==NULL)
 {
     head=temp;
 }
 else
 {
   while(cur->next!=NULL)
        cur=cur->next;
   cur->next = temp;
 }
}
/*void node::ins_end()
{
 node *temp;
 temp=new node;
 cout<<"Value:";
 cin>>temp->info;
 temp->next=0;
 if(head!=NULL && tail!=NULL)
 {
  tail->next=temp;
  tail=temp;
 }
 else
 {
  head=temp;
  tail=temp;
 }
}
void node::insert_beg()
{
 node *temp=new node;
 cout<<"Value:";
 cin>>temp->info;
 if(head!=NULL && tail!=NULL)
 {
  temp->next=head;
  head=temp;
 }
 else
 {
  head=temp;
  tail=temp;
 }
} */
void node::del()
{
 node *cur, *prev, *temp;
 int data;
 if(head==NULL)
    cout<<"No records to delete\n";
 else
 {
  cout<<"Enter the data to be deleted: ";
  cin>>data;
  cur=head;
  while((cur!=NULL)&&(cur->info!=data))
  {
   prev=cur;
   cur=cur->next;
  }
  if(cur==head)
  {
   head=head->next;
   cout<<"Data Deleted: "<<data<<endl;
  }
  if(cur==NULL)
  {
   cout<<"Record not found\n";
   return;
  }
  else
  {
   prev->next=cur->next;
   cout<<"Data deleted is: "<<data<<endl;
  }
 delete(cur);
 }
}

void node::del_beg()
{
 node *temp;
 temp=head;
 head=head->next;
 cout<<"\nDeleted element is:"<<temp->info;
 delete(temp);
}

void node::del_alternate()
{
 node *c, *c1;
 c = head;
 while(c!=NULL && c->next!=NULL)
 {
  c1 = c->next;
  c->next = c1->next;
  c = c->next;
  delete(c1);
 }
}

void node::ins_sort()
{
 node *c = head, *p;
 cout<<"Enter the element to be insrted into sorted list";
 node *temp = new node;
 cin>>temp->info;
 temp->next = NULL;
 if(temp->info < c->info)
 {
  temp->next = c;
  head = temp;
 }
 else
 {
  while((c!=NULL)&&(temp->info > c->info))
  {
   p = c;
   c = c->next;
  }
  temp ->next = c;
  p->next = temp;

 }
}

void node::print()
{
  node *h=head;
  if(h==NULL)
    cout<<"List is empty\n";
  while(h!=NULL)
  {
   cout<<"->"<<h->info;
   h=h->next;
  }
  cout<<endl;
}

int main()
{
 node n1;

 while(1)
 {
  cout<<"1.Insert Beginning \t 2. Insert end \t 3. Insert anywhere \t 4. Print\t 5. Delete Beg \t 6. Delete from Anywhere \t 7. Exit \t 8. Delete Alternate\n";
  cout<<"9. Insert into sorted \n";
  int ch;
  cin>>ch;
  switch(ch)
  {
   case 1: n1.insbegNOtail();
	   break;
   case 2: n1.insendNOtail(); break;
   case 3: n1.ins();break;
   case 4: n1.print(); break;
   case 5: n1.del_beg();break;
   case 6: n1.del(); break;
   case 7: exit(0);
   case 8: n1.del_alternate(); break;
   case 9: n1.ins_sort();break;
  }
 }
 return 0;
}
