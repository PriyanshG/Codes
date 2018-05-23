#include<iostream>
#include<stack>
#include<string.h>
using namespace std;
int main()
{
char s[100];
cout<<"Enter string";
cin>>s;
stack<char> A;
int i,l=strlen(s);
for(i=0;s[i]!='\0';i++)
    A.push(s[i]);
for(i=0;i<l;i++)
   {s[i]=A.top();A.pop();}
cout<<s;
}

