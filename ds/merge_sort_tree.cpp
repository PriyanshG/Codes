//https://codeforces.com/contest/459/problem/D

#include <bits/stdc++.h>
using namespace std;

#define ll long 
#define pll pair<ll,ll> 

#define left 2*node
#define right left+1
#define mid (s+e>>1)

const ll N=1e6+6;
ll A[N];
ll B[N];
ll C[N];
vector<ll> T[4*N];

void build(ll node, ll s, ll e){
	if(s==e){
		T[node]=vector<ll>(1,C[s]);
		return ;
	}

	build(left, s, mid);
	build(right, mid+1, e);
	merge(T[left].begin(), T[left].end(), T[right].begin(), T[right].end(), back_inserter(T[node]));
}

long long  query(ll node,ll s,ll e, ll x,ll y, ll val){
	if(s>e || e<x || s>y)
		return 0;
	if(x<=s && e<=y){
		ll a=upper_bound(T[node].begin(), T[node].end(), val)-T[node].begin();
		return a;
	}
	long long p1=query(left,s,mid, x, y, val);
	long long p2=query(right, mid+1, e, x, y, val);

	return p1+p2;
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
	}
	build(1,1,n);
	long long ans=0;
	for(ll i=0;i<n;i++){
		ans+=query(1,1,n,i+2,n,B[i]-1);
	}
	cout<<ans<<endl;

}

