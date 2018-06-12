#include<bits/stdc++.h>
using namespace std;
struct bstnode{
int data;
bstnode *left;
bstnode *right;
};

bstnode* ins(bstnode *root,int x)
{
    bstnode *newn=new bstnode;
    newn->data=x;
    newn->left=newn->right=NULL;
    if(root==NULL)
    {
        root=newn;
    }
    else if(x<=root->data)
    {
        root->left=ins(root->left,x);
    }
    else if(x>root->data)
    {
        root->right=ins(root->right,x);
    }
    return root;

}
bool ser(bstnode *root,int x)
{
    if(root==NULL) return false;
    else if(root->data==x) return true;
    else if(x<=root->data) return ser(root->left,x);
    else return ser(root->right,x);

}
int main()
{
    bstnode *root=NULL;
    root=ins(root,15);
    root=ins(root,10);
    root=ins(root,20);
    root=ins(root,25);
    if(ser(root,14))
        cout<<"FOUND";
    else
    cout<<"NOt";

}
