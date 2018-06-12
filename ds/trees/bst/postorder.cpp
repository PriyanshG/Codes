#include<bits/stdc++.h>
using namespace std;
struct tnode{
int data;
tnode *left;
tnode *right;
};

tnode* ins(tnode *root,int x)
{
    tnode *newn=new tnode;
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
void inorder(tnode *root)
{
    if(root==NULL)
        return;
        inorder(root->left);
    inorder(root->right);

    cout<<root->data<<" ";

}
int main()
{
    tnode *root=NULL;
    root=ins(root,15);
    root=ins(root,10);
    root=ins(root,20);
    root=ins(root,25);
    root=ins(root,17);
    root=ins(root,17);
    root=ins(root,23);
    inorder(root);

}
#include<bits/stdc++.h>
using namespace std;
struct tnode{
int data;
tnode *left;
tnode *right;
};

tnode* ins(tnode *root,int x)
{
    tnode *newn=new tnode;
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
void postorder(tnode *root)
{
    if(root==NULL)
        return;
        postorder(root->left);
    postorder(root->right);

    cout<<root->data<<" ";

}
int main()
{
    tnode *root=NULL;
    root=ins(root,15);
    root=ins(root,10);
    root=ins(root,20);
    root=ins(root,25);
    root=ins(root,17);
    root=ins(root,17);
    root=ins(root,23);
    postorder(root);

}
