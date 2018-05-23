#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
}*front=NULL,*rear=NULL;
void enq(int a)
{
    node *newn=new node;
    (*newn).data=a;
    newn->next=NULL;
    if(front==NULL && rear==NULL)
    {
     front=rear=newn;

    }
    else
    {
        rear->next=newn;
        rear=newn;
    }
}
void deq()
{
    if(front==NULL && rear==NULL)
    {
        cout<<"empty";
    }
    else if(front==rear)
    {
            node *temp;
            temp=front;
            front=rear=NULL;
    }
    else
    {node *temp;
            temp=front;
            front=front->next;
            delete temp;
    }
}
void emp()
{
    if(front==NULL)
        cout<<"empty\n";
    else
        cout<<"NOT";
}
void fro()
{

    if(front==NULL && rear==NULL)
        cout<<"empty";
    else cout<<front->data<<endl;

}
int main()
{int ch,a;
 char ans;
    do{
        cout<<"Enter \n\t1.To enqueue.\n\t2.To dequeqe\n\3.To see front\n\t4.To check empty. ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            cout<<"Enter number ";
            cin>>a;
            enq(a);
            break;
        case 2:
            deq();
            break;
        case 3:
            fro();
            break;
        case 4:
            emp();
            break;
        default:
            cout<<"wrong choice";
        }
        cout<<"Do you want to do more? ";
        cin>>ans;
    }while(ans=='y');
    return 0;
}
