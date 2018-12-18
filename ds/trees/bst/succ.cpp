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
tnode *ser(tnode *root,int x)
{

if(root==NULL)
    return root;
else if(root->data==x)
    return root;
else if(root->data<x)
    return ser(root->right,x);
else
    return ser(root->left,x);
}
tnode* succ(tnode *root,int x)
{
    tnode* cur=ser(root,x);
    if(cur==NULL)
     return NULL;
    if(cur->right!=NULL)
    {
        tnode *temp=cur->right;
        while(temp->left!=NULL)
        {
            temp=temp->left;
        }
        return temp;

    }
    else
    {
        tnode *anc=root;
        tnode *succe=NULL;
        while(anc!=cur)
        {
            if(anc->data>cur->data)
            {

                succe=anc;
                anc=anc->left;
            }
            else
                anc=anc->right;
        }
        return succe;
    }

}
int main()
{
    tnode *root=NULL;
    root=ins(root,15);
    root=ins(root,10);
    root=ins(root,20);
    root=ins(root,25);
    root=ins(root,17);
    root=ins(root,16);
    root=ins(root,8);
    root=ins(root,6);
    root=ins(root,11);
    root=ins(root,27);
    root=ins(root,12);
    tnode *ans=succ(root,6);
    if(ans!=NULL)
        cout<<ans->data;
    else cout<<"NOT";

}
