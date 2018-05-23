#include<bits/stdc++.h>
using namespace std;
struct node{
int data;
node *next;
}*head=NULL;
void input(int a)
{

node* temp=new node;
temp->data=a;
temp->next=head;
head=temp;
}
void inputn(int a,int n)
{int i;
node *newt=new node;
newt->data=a;
newt->next=head;
if(n==1)
{
    head=newt;

}
else{
node* temp=new node;
temp=head;
for(i=1;i<n-1;i++)
{
    temp=temp->next;

}
newt->next=temp->next;
temp->next=newt;
}

}
void print()
{
    node *temp=new node;
    temp=head;
    while(temp!=NULL)
    {

        cout<<(temp->data)<<" ";
        temp=temp->next;
    }
}
stack<int> A;
void rev()
{
    node *temp;
    temp=head;
    while(temp!=NULL)
    {
        A.push(temp->data);
        temp=temp->next;

    }
    temp=head;
    while(temp!=NULL)
    {
        temp->data=A.top();
        A.pop();
        temp=temp->next;
    }
}
int main()
{int n,i,a;
 cout<<"Enter size";
    cin>>n;
    for(i=0;i<n;i++)
    {cout<<"Enter number";
       cin>>a;
        input(a);
        cout<<"LIST is ";
        print();
        cout<<endl;
    }
  rev();
    print();


}
