//https://codeforces.com/contest/459/problem/D

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll> 

const ll N=1e6+6;
ll A[N];
ll B[N];
ll C[N];
struct node{
	ll pos;
	ll l;
	ll r;
	ll val;
}T[2*N];
ll D[N];

void upd(ll x,ll n){
	while(x<=n){
		D[x]++;
		x+=x&(-x);
	}
}

ll query(ll x,ll n){
	ll ans=0;
	while(x){
		ans+=D[x];
		x-=x&(-x);
	}
	return ans;
}


bool comp(node a, node b){
	if(a.val==b.val)
		return a.pos<b.pos;
	return a.val<b.val;
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n;
	cin>>n;
	map<ll,ll> M;
	for(ll i=0;i<n;i++){
		cin>>A[i];
		M[A[i]]++;
		B[i]=M[A[i]];
	}
	M.clear();
	for(ll i=n-1;i>=0;i--){
		M[A[i]]++;
		C[i+1]=M[A[i]];
		T[i+1].pos=0;
		T[i+1].l=0;
		T[i+1].r=i+1;
		T[i+1].val=C[i+1];
	}
	for(ll i=0;i<n-1;i++){
		T[n+i+1].pos=i+1;
		T[n+i+1].l=i+2;
		T[n+i+1].r=n;
		T[n+i+1].val=B[i]-1;
	}

	sort(T+1,T+2*n,comp);
	ll ans=0;
	for(ll i=1;i<2*n;i++){
		if(T[i].pos==0)
			upd(T[i].r,n);
		else ans+=query(T[i].r,n)-query(T[i].l-1,n);
	}
	cout<<ans<<endl;
}

