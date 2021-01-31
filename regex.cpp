//https://atcoder.jp/contests/abc049/tasks/arc065_a

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
	regex e("(dream|dreamer|erase|eraser)+");
	if(regex_match(s,e))
		cout<<"YES";
	else cout<<"NO";
	cout<<endl;
}


