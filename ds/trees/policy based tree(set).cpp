//http://codeforces.com/blog/entry/11080
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ll long long

typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> Ptree;

Ptree A;
void insert(){
	cout<<"Enter element ";
	ll x;

	cin>>x;
	A.insert(x);
	cout<<"\n"<<x<<" has been inserted ";

}

void del(){
	
	cout<<"Enter element which you want to delete ";
	ll x;
	cin>>x;
	if(A.find(x)!=A.end()){
		A.erase(x);
	}
	else
		cout<<"x is not in tree ";
}
void op1(){
	cout<<"Enter value of k to find the kth smallest element ";
	ll k;
	cin>>k;
	k--;
	if(A.size()>k)
	cout<<*A.find_by_order(k)<<"is the kth largest number"<<endl;
	else cout<<"Tree has less element ";
}
void op2(){

	ll x;
	cout<<"Enter the value of x to find the number of element less than x ";
	cin>>x;
	cout<<(A.order_of_key(x))<<" are strictly less than x \n";
}
int main(){
	
	ll c;
	do{
		cout<<"\n\nEnter 1.To enter an element\n\t2.To delete an elemet\n\t3.To find kth smallest element \n\t4.To find the number of element which are less than 5.To exit ";
		cin>>c;
		switch(c){

			case 1:
				insert();
				break;
			case 2:
				del();
				break;
			case 3:
				op1();
				break;
			case 4:
				op2();
				break;
		}
	}while(c!=5);
}

