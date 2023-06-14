#include <iostream>
using namespace std;
class list
{
	int data;
	list *link;
 public:
	list* create(list*,int);
	void traverse(list *);
list* mwithout_new(list *,list *);
};
list *first1=NULL,*first2=NULL,*first3=NULL;

list* list::create(list *first, int ele)
{
	list *temp,*curr;
	temp=new list;
	temp->data=ele;
	temp->link=NULL;
	if(first==NULL)
		first=temp;
	else
	{
		for(curr=first;curr->link!=NULL;curr=curr->link);
		curr->link=temp;
	}
	return first;
}
void list::traverse(list *first)
{
	if(first==NULL)
		cout<<"\nlist is empty";
	else
	{
		cout<<"\nthe list is:\n";
		for(list *curr=first;curr!=NULL;curr=curr->link)
			cout<<curr->data<<"\t";
	}
}

list* list::mwithout_new(list *firsta,list *firstb)
{
	list *curra=firsta;
	list *preva=NULL,*prevb=NULL;
	list *currb=firstb;
	list *res=NULL; int pa=0,pb=0;
    
    if(first1->data<=first2->data) 
    {
        pa=1;
        res=firsta;
    }
    else 
    {
         pb=1;
        res=firstb;
    }
       
	while(curra!=NULL&&currb!=NULL)
	{
		if(curra->data<=currb->data)
		{
			if(pb==1)
            {
                prevb->link=curra;
                pa=1;
                pb=0;
            }
            preva=curra;
			curra=curra->link;
		}
		else //curra->data>currb->data
		{
            if(pa==1) 
            {
                preva->link=currb;
               pa=0;
                pb=1;
            }
           prevb=currb;
        currb=currb->link;
		}
	}
	if(curra)
        prevb->link=curra;
    if(currb)
        preva->link=currb;
	traverse(res);
	return(res);
}

int main()
{
//	clrscr();
	list l1,l2;
	first1=l1.create(first1,5);
    first1=l1.create(first1,10);
    first1=l1.create(first1,15);
    first2=l1.create(first2,3);
    first2=l1.create(first2,6);
    first2=l1.create(first2,9);
    first2=l1.create(first2,12);
    l1.traverse(first1);
    l1.traverse(first2);
    first3=l1.mwithout_new(first1,first2);
    l1.traverse(first3);
return 0;
}

OUTPUT:
the list is:
5	10	15	
the list is:
3	6	9	12	
the list is:
3	5	6	9	10	12	15	
the list is:
3	5	6	9	10	12	15	