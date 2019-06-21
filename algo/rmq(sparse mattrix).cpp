#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
	ll n,m;
	cin>>n;
	vector<ll> A(n);
	ll x,d,u,y;
	for(ll i=0;i<n;i++)
		cin>>A[i];
		cin>>m;

	ll lg[n+1]={0};
	for(ll i=2;i<=n;i++)
		lg[i]=lg[i/2]+1;
	vector<ll> B[lg[n]+1];
	B[0]=A;
	for(ll i=1;i<=lg[n];i++)
		for(ll j=0;j<n-(1<<i)+1;j++)
			B[i].push_back(min(B[i-1][j],B[i-1][j+(1<<(i-1))]));
	for(ll i=0;i<m;i++){
		cin>>x>>y;
		if(y<x) swap(y,x);
		d=y-x+1;
		u=lg[d];
		cout<<min(B[u][x],B[u][y-(1<<u)+1])<<"\n";
	}
}

 
