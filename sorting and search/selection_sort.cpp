#include<iostream>
using namespace std;

int main()
{


int n=5,flag=0,A[100]={23,223,32,12,34},i,j,t,sm,pos;

for(i=0;i<n-1;i++)
{
    sm=A[i];
    for(j=i+1;j<n;j++)
    {
        if(sm>A[j])
        {flag=1;
            pos=j;
            sm=A[j];
        }
    }
    if(flag==1)
    {
    t=A[i];
    A[i]=A[pos];
    A[pos]=t;
    flag=0;}
}
cout<<endl;
for(i=0;i<n;i++)
{cout<<A[i]<<endl;
}}
