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



}
