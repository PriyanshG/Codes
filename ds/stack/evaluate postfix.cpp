#include<iostream>
#include<stack>
using namespace std;
int main()
{int a,i;
 stack<int> A;
 char s[100];
    cout<<"enter expression";
    cin>>s;
    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
        {

            a=A.top();
            A.pop();
            if(s[i]=='*')
            a=a*A.top();
            else if(s[i]=='+')
            a=a+A.top();
            else if(s[i]=='-')
            a=A.top()-a;
            else if(s[i]=='/')
            a=A.top()/a;
            A.pop();
            A.push(a);
        }
        else
        {

            A.push(s[i]-48);
        }
    }
    cout<<A.top();
}
