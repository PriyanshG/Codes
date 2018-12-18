#include<iostream>
using namespace std;

int main()
{


int n=5,flag=0,A[100]={-1,23,223,32,12,34},i,j,t,sm,pos;
for(i=1;i<=n;i++)
{

t=A[i];
j=i-1;
while(t<A[j])
{
    A[j+1]=A[j];
    j--;
}
A[j+1]=t;

}
for(i=1;i<=n;i++)
{cout<<A[i]<<endl;
}}
