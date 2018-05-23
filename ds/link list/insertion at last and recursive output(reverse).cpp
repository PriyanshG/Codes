#include<bits/stdc++.h>
using namespace std;
struct node{
int data;
node *next;
}*head;
void insert(int x)
{   node *temp=new node;
    node*temp1=new node;
    temp=head;
   node *newnode=new node;
   newnode->data=x;
   newnode->next=NULL;
   if(head==NULL)
   {
       head=newnode;
   }
   else{
   while(temp!=NULL)
   {    temp1=temp;
       temp=temp->next;
   }
   temp1->next=newnode;}
}
void print()
{

node *temp=new node;
temp=head;
while(temp!=NULL)
{

    cout<<temp->data<<" ";
    temp=temp->next;
}
}

void rev(node *temp)
{
    if(temp==NULL)
        return ;
 rev(temp->next);
 cout<<temp->data<<" ";
}

int main()
{int n,i,a;
    cout<<"Enter size";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"enter number";
        cin>>a;
        insert(a);
        cout<<"LIst is";
        print();
        cout<<endl;
    }

    rev(head);

    }

