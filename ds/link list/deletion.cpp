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
void del(int n)
{int i,flag=0;
    node *temp=new node;
    node *temp1=new node;
    temp1=NULL;
    temp=head;
    if(temp==NULL)
        cout<<"EMPTY";
    else if(n==1)
    {

        head=temp->next;
    }
        else{
    for(i=1;i<n;i++)
    {
        temp1=temp;
        temp=temp->next;
        if(temp==NULL)
            {cout<<"OUT OF BOUND";flag=1;break;}
    }
    if(flag==0)
    {
        temp1->next=temp->next;
    }

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
    cout<<"Enter where u want to add";
    cin>>n;
    del(n);
    print();


}
