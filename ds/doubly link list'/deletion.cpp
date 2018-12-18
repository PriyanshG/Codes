#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
    node *prev;
}*head;
void insert(int a)
{
    node *newnode=new node;
    newnode->data=a;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(head==NULL)
    {
        head=newnode;
        return;
    }
    node *temp;
    temp=head;
    temp->prev=newnode;
    newnode->next=temp;
    head=newnode;
}
void del(int n)
{
int i;
node *temp;
temp=head;
if(head==NULL)
   {cout<<"Empty";
    return;}
else if(n==1)
{
    head=head->next;head->prev=NULL;
    return;
}
for(i=0;i<n-1;i++)
{

    temp=temp->next;
}
(temp->prev)->next=temp->next;
}
void print()
{

node *temp;
temp=head;
while(temp!=NULL)
{

    cout<<temp->data<<" ";
    temp=temp->next;
}
}
int main()
{
  int n,i,a;
  cout<<"Enter size";
  cin>>n;
  for(i=0;i<n;i++)
  {
      cin>>a;
      insert(a);
      cout<<"LIST IS ";
      print();
      cout<<endl;

  }
cin>>a;
  del(a);
  print();

}
