#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
struct Node *insert_rear(int ele,struct Node *first)
{
   struct Node *ptr;
   ptr = (struct Node *)malloc(sizeof(struct Node *));
   ptr->data = ele;
   if(first == NULL)
   {
    ptr->next = NULL;
    return ptr;
   }
   struct Node *temp = first;;
   while(temp->next != NULL)
   {
    temp = temp->next;
   }
   temp->next = ptr;
   ptr->next = NULL;
   return first;
}
void display(struct Node *first)
{
    if(first == NULL)
    {
        printf("List is empty\n");
        exit(0);
    }
    printf("Contents of list are\n");
    struct Node *temp = first;
   do
    {
        printf("%d\n",temp->data);
     temp = temp->next;
    }while(temp != first);
}

struct Node *rightrotate(struct Node *first,int k,int n)
{
  struct Node *temp = first;
  int count =0;
  while(count != n-k)
  {
    temp = temp->next;
    count++;
  }
  return temp;
}

struct Node *leftrotate(struct Node *first,int k)
{
   struct Node *temp = first;
  int count =0;
  while(count!=k)
  {
    temp = temp->next;
    count++;
  }
  return temp;
}

int main()
{
    struct Node *head1;
    struct Node *head2;

    head1 = (struct Node *)malloc(sizeof(struct Node *));
    head2 = (struct Node *)malloc(sizeof(struct Node *));
    printf("Enter number of elements\n");
    int n1,t;
    scanf("%d",&n1);
    printf("Enter elements \n");
    for(int i=0;i<n1;i++)
    {
        scanf("%d",&t);
        head1 = insert_rear(t,head1);
        head2 = insert_rear(t,head2);
    }
    struct Node *temp1 = head1;
    struct Node *temp2 = head2;
     while(temp1->next != NULL)
    {
        temp1 = temp1->next;
    }
     while(temp2->next != NULL)
    {
        temp2 = temp2->next;
    }

    struct Node *t1 = head1->next;
    free(head1);
    head1 = t1;
    struct Node *t2 = head2->next;
    free(head2);
    head2 = t2;
     temp2->next = head2;
    temp1->next = head1;
    printf("Enter k\n");
    int k;
    scanf("%d",&k);
    display(head1);
   head1=leftrotate(head1,k);
   printf("After rotating left :\n");
   display(head1);
   head2 = rightrotate(head2,k,n1);
   printf("After rotating right :\n");
   display(head2);
    return 0;
}