// https://www.hackerearth.com/practice/algorithms/string-algorithm/manachars-algorithm/tutorial/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll> 

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	string s;
	cin>>s;
	ll c=0,r=0;

	string w="@";
	for(ll i=0;i<s.size();i++)
		w+="#"+s.substr(i,1);
	w+="#$";

	ll n=w.size();
	ll P[n]={0};
	for(ll i=1;i<n-1;i++){
		ll d=(i-c);
		if(i<r)
			P[i]=min(r-i,P[c-d]);
		while(w[i-1-P[i]]==w[i+1+P[i]]){
			P[i]++;
		}
		if(i+P[i]>r){
			c=i;
			r=i+P[i];
		}
	}
	ll ans=0,center=0;

	vector<ll> Q(s.size(),1);
	for(ll i=1;i<n-1;i++){
		Q[(i-P[i]-1)/2]=max(Q[(i-P[i]-1)/2], P[i]);

		// if only odd length palindrome is required then just 
		// apply a condition "if(i%2==0) on above line and
		// alter this for even length palindrome
	}
	ll x=max_element(Q.begin(),Q.end())-Q.begin();
	cout<<Q[x]<<endl;
	cout<<s.substr(x, Q[x]);
}
