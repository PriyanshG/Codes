 
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll N=10005;
ll Z[N]={0};
ll M[N]={0};
ll V[N]={0};
vector<ll> B;
ll co=0,c=0;;

unordered_map<ll,ll> Ma;
ll val(ll x){
	if(M[x]==0){
		Z[x]=co;
		M[x]=++c;
		Ma[c]=x;
	}
	co++;
	return M[x];
}
void dfs(vector<ll> A[],ll x){
	V[x]=1;
	ll f=0;
	for(auto it:A[x]){
		if(V[it]==0){
			f=1;
			B.push_back(val(x));
			dfs(A,it);
		}
	}
	B.push_back(val(x));
}

int main(){
	

	//freopen("input.txt","r",stdin);
	ll r=0;
	ll t;
	cin>>t;
	ll lg[N+1]={0};
	for(ll i=2;i<N;i++)
		lg[i]=lg[i/2]+1;
	

	while(t--){
		cout<<"Case "<<++r<<":\n";
		c=co=0;
		B.clear();
		ll n;
		cin>>n;
		ll x,y,u,v;
		vector<ll> A[n+1];
		for(ll i=0;i<n;i++){
			ll q;
			cin>>q;
			for(ll j=0;j<q;j++){
				cin>>x;
				A[i+1].push_back(x);
				A[x].push_back(i+1);
			}
		}
		memset(V,0,sizeof(V));
		memset(M,0,sizeof(V));
		memset(Z,0,sizeof(V));
		dfs(A,1);

		ll m=B.size();
		vector<ll> C[lg[m]+1];
		C[0]=B;
		for(ll i=1;i<=lg[m];i++)
			for(ll j=0;j<m-(1<<i)+1;j++)
				C[i].push_back(min(C[i-1][j],C[i-1][j+(1<<(i-1))]));
		ll q;
		cin>>q;
		while(q--){
			cin>>u>>v;
			x=Z[u];
			y=Z[v];
			if(x>y)
				swap(x,y);
			ll d=y-x+1;
			u=lg[d];
			ll as= min(C[u][x],C[u][y-(1<<u)+1]);
			cout<<Ma[min(C[u][x],C[u][y-(1<<u)+1])]<<"\n";
		}
	}
}
