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

}
