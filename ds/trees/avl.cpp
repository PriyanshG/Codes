#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(i,a,b) for(ll i=a;i<b;i++)


struct node 
{
	ll val;
	node *l;
	node *r;
	ll h;
	ll c;
};

node *nnode(ll x)
{
	node* root=new node;
	root->val=x;
	root->l=NULL;
	root->r=NULL;
	root->h=1;
	root->c=0;
	return root;
}

ll child(node* x)
{
	if(x==NULL)
		return 0;
	else
		return x->c+1;
}ll height(node* x)
{
	if(x==NULL)
		return 0;
	else
		return x->h;
}
node *rrot(node *z)
{
	node * y=z->l;
	z->l=y->r;
	y->r=z;

	z->h=max(height(z->l),height(z->r))+1;
	y->h=max(height(y->l),height(y->r))+1;

	z->c=child(z->l)+child(z->r);
	y->c=child(y->l)+child(y->r);

return y;
}

node *lrot(node *z)
{
	node *y=z->r;
	z->r=y->l;
	y->l=z;

	z->h=max(height(z->l),height(z->r))+1;
	y->h=max(height(y->l),height(y->r))+1;

	z->c=child(z->l)+child(z->r);
	y->c=child(y->l)+child(y->r);
	return y;
}

ll getb(node *x)
{
	if(x==NULL)
		return 0;
	else
	return 	height(x->l)-height(x->r);
}

node *ins(node *root,int val)
{
	if(root==NULL)
		return nnode(val);
	
	if(val<root->val){
		root->c++;
	  root->l=ins(root->l,val);
	}
	else if(val>root->val){
		root->c++;
		root->r=ins(root->r,val);
	}
	else
		return root;

	root->h=1+max(height(root->l),height(root->r));
	ll bal=getb(root);

	if(bal>1 && val<root->l->val)
		return rrot(root);
	else if(bal>1 && val>root->l->val){
		root->l=lrot(root->l);
		return rrot(root);
	}
	else if(bal<-1 && val>root->r->val)
		return lrot(root);
	else if(bal<-1 && val<root->r->val){
		root->r=rrot(root->r);
		return lrot(root);
	}
	return root;
}

node *minvalue(node * root)
{
	if(root==NULL)
		return root;
	node *temp=root;
	while(temp->l!=NULL)
		temp=temp->l;
	return temp;
}
		
node *del(node *root,int val)
{
	if(root==NULL)
		return root;
	if(val<root->val){
		root->c--;
		root->l=del(root->l,val);
	}
	else if(val>root->val){
		root->c--;
		root->r=del(root->r,val);
	}
	else
	{
		if(root->l==NULL)
		{
			node *temp=root->r;
			free(root);
			return temp;
		}
		if(root->r==NULL)
		{
			node *temp=root->l;
			free(root);
			return temp;
		}

		node *temp=minvalue(root->r);
		root->val=temp->val;
		root->r=del(root->r,temp->val);
	}
	root->h=1+max(height(root->l),height(root->r));
	ll bal=getb(root);

	if(bal>1 && val<root->l->val)
		return rrot(root);
	else if(bal>1 && val>root->l->val){
		root->l=lrot(root->l);
		return rrot(root);
	}
	else if(bal<-1 && val>root->r->val)
		return lrot(root);
	else if(bal<-1 && val<root->r->val){
		root->r=rrot(root->r);
		return lrot(root);
	}
	return root;
}
			
void pre(node * root)
{
	if(root!=NULL)
	{
		pre(root->l);
		cout<<root->val<<" "<<root->h<<" "<<root->c<<"\n";
		pre(root->r);
	}
}


int main()
{
	ll q,x;
	char ch;
	cin>>q;
	node *root=NULL;
	while(q--)
	{
		cin>>ch;
		if(ch=='I')
		{
			cin>>x;
			root=ins(root,x);
pre(root);
		}

		else if(ch=='D')
		{
pre(root);
			cin>>x;
			root=del(root,x);
pre(root);
		}
	}

}

 
