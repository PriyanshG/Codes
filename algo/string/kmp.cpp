#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(i,a,b) for(ll  i=a;i<b;i++)

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		string t,p;
		cin>>t>>p;
		ll m=p.size();
		ll n=t.size();
		ll A[m]={0};
		ll j=0;
		set<ll> S;
		loop(i,1,m)
		{
			j=A[i-1];
			while(j && p[i]!=p[j])
				j=A[j-1];
			if(p[j]==p[i])
				j++;
			A[i]=j;
		}
		j=0;
		loop(i,0,n)
		{
			while(j && p[j]!=t[i])
				j=A[j-1];
				if(p[j]==t[i])
					j++;
				if(j==p.size()){
					S.insert(i+2-p.size());
					j=A[j-1];
				}
		}
		if(S.size()==0)
			cout<<"Not Found\n";
		else
		{
			cout<<S.size()<<endl;
			for(auto it:S)
				cout<<it<<" ";
			cout<<endl;
		}
		

	}
}

