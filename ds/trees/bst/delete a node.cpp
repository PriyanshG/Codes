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
tnode *finmin(tnode *root)
{
    if(root->right==NULL && root->left==NULL)
    { return root;
    }
    else if(root->left!=NULL)
   return finmin(root->left);
   return root;

}

tnode *del(tnode *root,int x)
{
    if(root==NULL)
        return root;
    else if(x<root->data)
     root->left=del(root->left,x);
    else if(x>root->data)
        root->right=del(root->right,x);
    else
    {
        if(root->right==NULL && root->left==NULL)
        {

            delete root;
            root=NULL;

        }
        else if(root->right==NULL)
        {
            tnode *temp=root;

            root=root->left;
            delete temp;

        }
        else if(root->left==NULL)
        {
            tnode *temp=root;
            root=root->right;
            delete temp;

        }
        else
        {
            tnode *temp=finmin(root->right);
            root->data=temp->data;
            root->right=del(root->right,root->data);
        }

    }return root;

}
void prin(tnode *root)
{
    if(root==NULL)
        return;
    prin(root->left);
    cout<<root->data<<" ";
    prin(root->right);

}

int main()
{
    tnode *root=NULL;
    root=ins(root,15);
    root=ins(root,10);
    root=ins(root,20);
    root=ins(root,25);
    root=ins(root,17);
    root=ins(root,19);
    root=ins(root,23);
    root=ins(root,17);
    root=ins(root,28);
    prin(root);
    cout<<endl;
   del(root,17);
   prin(root);

}
