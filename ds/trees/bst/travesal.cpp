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
queue<bstnode *> Q;
void ttraverse(bstnode *root)
{
    if(root==NULL)
    {
        cout<<"Empty";
    }
    else
    {Q.push(root);
        while(!Q.empty())
    {
    bstnode *cur=Q.front();
    cout<<cur->data<<" ";
     if(cur->left!=NULL) Q.push(cur->left);
     if(cur->right!=NULL)
     Q.push(cur->right);
     Q.pop();
    }
    }
}
int main()
{
    bstnode *root=NULL;
    root=ins(root,15);
    root=ins(root,10);
    root=ins(root,20);
    root=ins(root,25);
    root=ins(root,17);
    root=ins(root,17);
    root=ins(root,23);
    ttraverse(root);

}
