#include<iostream>
#include<stack>
using namespace std;
int main()
{char s[100];
int i,flag=0;
stack<char> A;
    cout<<"Enter string";
    cin>>s;
    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]=='(' || s[i]=='{')
            {
                A.push(s[i]);
            }
        else if(s[i]==')' || s[i]=='}')
        {
            if(A.empty())
            {
                flag=1;
                break;
            }
            else if(s[i]==')' && A.top()!='(' || s[i]=='}' && A.top()!='{')
            {
                flag=1;break;
            }
            else if(s[i]==')' && A.top()=='(' || s[i]=='}' && A.top()=='{')
            {
                A.pop();
            }
        }


    }

    if(flag==1 || !A.empty())
        cout<<"wrong";
    else cout<<"right";
}
