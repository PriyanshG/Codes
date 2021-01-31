//a^y mod m=b mod m
#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll mpow(ll a,ll b,ll m){
	ll x=1;
	a%=m;
	b%=m;
	while(b>0){
		if(b&1)
			x=a*x%m;
		a=a*a%m;
		b>>=1;
	}
	return x;
}

ll func(ll a,ll b,ll m){

	if(b==1)
		return 0;

	
	ll c=0;
	ll f1=1;
	ll g=__gcd(a,m);
	while(g!=1){
		if(b%g)
			return INT_MAX;
		b/=g;
		m/=g;
		f1=(f1*(a/g))%m;
		c++;
		if(b==f1)
			return c;
		g=__gcd(a,m);
	}

	unordered_map<ll,vector<ll> > M;
	ll n=sqrt(1.0*m)+1;
	ll x=mpow(a,n,m);
	ll m1=INT_MAX;

	for(ll i=1;i<=n;i++){
		f1=f1*x%m;
		M[f1].push_back(i);
	} 

	ll f2=b;
	for(ll i=0;i<=n;i++){
		if(M.find(f2)!=M.end()){
			for(auto it:M[f2])
				m1=min(m1,n*it-i+c);
		}
		f2=f2*a%m;
	}
	return m1;
}


int main(){
	ll x,z,k;
	while(cin>>x>>z>>k){
		if(x==0)
			break;
		ll ans=func(x,k,z);
		if(ans==INT_MAX)
			cout<<"No Solution";
		else cout<<ans;
		cout<<endl;
	}
}


