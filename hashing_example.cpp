// https://www.spoj.com/problems/NHAY/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll> 
const ll p=31,r=39;
const ll m1=1e9+7, m2=1e9+87;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n;
	while(cin>>n){
		string s,w;
		cin>>s>>w;
		ll P[n+1]={},R[n+1]={};
		P[0]=R[0]=1;
		for(ll i=1;i<=n;i++){
			P[i]=(P[i-1]*p)%m1;
			R[i]=(R[i-1]*r)%m2;
		}
		ll x,y,a,b;
		x=y=a=b=0;

		for(ll i=0;i<n;i++){
			a=(a+(s[i]-'a'+1)*P[n-i])%m1;
			b=(b+(s[i]-'a'+1)*R[n-i])%m2;
			if(i<w.size()){
				x=(x+(w[i]-'a'+1)*P[n-i])%m1;
				y=(y+(w[i]-'a'+1)*R[n-i])%m2;
			}
		}
		if(x==a && y==b)
			cout<<0<<"\n";

		for(ll i=n;i<w.size();i++){
			x=(x-((w[i-n]-'a'+1)*P[n])%m1+m1)%m1;
			y=(y-((w[i-n]-'a'+1)*R[n])%m2+m2)%m2;
			x=(x*p)%m1;
			y=(y*r)%m2;
			x=(x+((w[i]-'a'+1)*P[1])%m1)%m1;
			y=(y+((w[i]-'a'+1)*R[1])%m2)%m2;
			if(x==a && y==b)
				cout<<i-n+1<<"\n";
		}
		cout<<endl;
	}
}

