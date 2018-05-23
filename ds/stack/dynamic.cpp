#include<iostream>
using namespace std;
struct node {
int data;
node* next;
}*head=NULL;

int main()
{
   char ans;
   int ch,a;
    do
    {
        cout<<"What you want to do?\n\t1.To Push\n\t2.To Pop\n\t3.To check whether it is empty\n\t4.To view top one";
        cin>>ch;
        switch(ch)
        {
        case 1:
            {cout<<"Enter number ";
            cin>>a;
            node* newnode=new node;
            newnode->data=a;
            newnode->next=head;
            head=newnode;
            }break;


        case 2:
           {if(head==NULL)
            cout<<"Empty";
           else
           {
               node *temp;
               temp=head;
               head=temp->next;
               delete temp;
           }
           }break;


        case 4:
            if(head==NULL)
                cout<<"First Push some element!!";
            else
                cout<<"Top is "<<head->data;
                break;
        default :
            cout<<"wrong choice";
        }
        cout<<"do you want to do more operations?";
        cin>>ans;
    }while(ans=='y');
}

