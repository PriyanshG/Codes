#include<iostream>
using namespace std;
int main()
{
    char ans;
    int A[100],a,ch,top=-1;
    const int size=5;
    do
    {
        cout<<"What you want to do?\n\t1.To Push\n\t2.To Pop\n\t3.To check whether it is empty\n\t4.To view top one";
        cin>>ch;
        switch(ch)
        {
        case 1:
            if(top==size)
            {cout<<"Please pop something first!!"; break;}
            cout<<"Enter number";
            cin>>a;
            A[++top]=a;
            break;
        case 2:
            if(top==-1)
                cout<<"Empty";
            else{
                top--;
            }
            break;

        case 3:
            if(top==-1)
                cout<<"Empty";
            else
                cout<<"Not empty";
            break;
        case 4:
            if(top==-1)
                cout<<"First Push some element!!";
            else
                cout<<"Top is "<<A[top];
                break;
        default :
            cout<<"wrong choice";
        }
        cout<<"do you want to do more operations?";
        cin>>ans;
    }while(ans=='y');
}
