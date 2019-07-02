
//spoj lca
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll> 
const ll  N=1e4+5;

ll P[N]={0};
ll V[N]={0};
ll D[N]={0};

void dfs(vector<ll> A[],ll x){
	V[x]=1;
	for(auto it:A[x])
		if(!V[it]){
			P[it]=x;
			D[it]=D[x]+1;
			dfs(A,it);
		}
}

ll q=0;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll t;
	cin>>t;
	while(t--){
		ll n;
		memset(P,0,sizeof(P));
		memset(D,0,sizeof(P));
		memset(V,0,sizeof(P));
		cin>>n;
		ll x;
		ll a;
		vector<ll> A[n+1];
		for(ll i=0;i<n;i++){
			cin>>x;
			for(ll j=0;j<x;j++){
				cin>>a;
				A[i+1].push_back(a);
				A[a].push_back(i+1);
			}
		}
		D[1]=0;
		P[1]=1;
		dfs(A,1);
		ll h=log2(n)+1;
		ll dp[n+1][h+1];
		for(ll i=0;i<=n;i++)
			for(ll j=0;j<=h;j++)
				dp[i][j]=-1;

		for(ll i=1;i<=n;i++)
			dp[i][0]=P[i];

		for(ll j=1;j<=h;j++)
			for(ll i=1;i<=n;i++)
				if(j<=D[i] &&dp[i][j-1]!=-1)
					dp[i][j]=dp[dp[i][j-1]][j-1];
		ll m;
		cin>>m;
//kth ancestor
//		while(m--){ 								
//			ll x,k;
//			cin>>x>>k;
//			if(k>D[x]){
//				cout<<"Not possible";
//			    continue;
//			}
//			for(ll i=h;i>=0;i--)
//				if(dp[x][i]!=-1 && (1<<i)<=k){
//					x=dp[x][i];
//					k=k-(1<<i);	
//				}
//			cout<<x<<endl;
//		}
		q++;
		cout<<"Case "<<q<<":"<<endl;
		while(m--){
			ll x,y;
			cin>>x>>y;
			if(D[y]>D[x])
				swap(x,y);
			ll c=x;
			for(ll i=h;i>=0;i--)
				if(D[c]-(1<<i)>=D[y])
					c=dp[c][i];

			if(y==c){
				cout<<y<<endl;
				continue;
			}

			for(ll i=h;i>=0;i--)
				if(dp[y][i]!=-1 && dp[y][i]!=dp[c][i]){
					y=dp[y][i];
					c=dp[c][i];
				}
			cout<<P[y]<<endl;
		}

	}
				

}

