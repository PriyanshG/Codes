#include<bits/stdc++.h>
using namespace std;

#define mem(A) memset(A,0,sizeof(A))
#define loop(i,a,n) for(long long i=a;i<n;i++)
#define pb push_back
#define mkp make_pair
#define prq priority_queue
#define fir first
#define sec second
#define all(A) A.begin(),A.end()
#define mod 1000000007
#define take(t) ll t;cin>>t;

typedef long long ll;
typedef pair<ll,ll> pll;
ll func(vector<ll> L,ll x)
{
    ll u=L.size()-1,l=-1;
    while(u-l>1)
    {
        ll mid=(u+l)>>1;
        if(L[mid]<x)
            l=mid;
        else
            u=mid;
    }

    return u;
}
int main()
{   //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,i,j;
    vector<ll> A;
    while(cin>>n)
        A.pb(n);
    n=A.size();
    vector<ll> L;
    L.pb(A[0]);
    loop(i,1,n)
    {
        ll a=A[i],b=L[L.size()-1];
        if(A[i]<L[L.size()-1])
        {


           ll  pos=func(L,A[i]);
            L[pos]=A[i];
        }
        else if(A[i]>L[L.size()-1])
            L.pb(A[i]);
      //  loop(i,0,L.size())
         //cout<<L[i]<<" ";
        //cout<<endl;
    }
    cout<<L.size()<<"\n-\n";
    loop(i,0,L.size())
     cout<<L[i]<<endl;

}
