#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll> 
const ll pinf=1e18+4;
const ll ninf=-pinf;

ll n;
void add(ll B[],ll x,ll v){
	while(x<=n){
		B[x]+=v;
		x+=x&(-x);
	}
}

ll sum(ll B[],ll x){
	ll s=0;
	while(x>0){
		s+=B[x];
		x-=x&(-x);
	}
	return s;
}
ll sr(ll B1[],ll B2[],ll x){
	return sum(B1,x)*x-sum(B2,x);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll t;
	cin>>t;
	while(t--){
		ll c;
		cin>>n>>c;
		ll B1[n+1],B2[n];
		memset(B1,0,sizeof(B1));
		memset(B2,0,sizeof(B2));
		while(c--){
			ll ch,x,y,v;
			cin>>ch;
			if(ch==0){
				cin>>x>>y>>v;
				add(B1,x,v);
				add(B1,y+1,-v);
				add(B2,x,(x-1)*v);
				add(B2,y+1,-y*v);
			}
			else{
				cin>>x>>y;
				cout<<sr(B1,B2,y)-sr(B1,B2,x-1)<<endl;
			}
		}
	}
}
https://www.spoj.com/problems/HORRIBLE/