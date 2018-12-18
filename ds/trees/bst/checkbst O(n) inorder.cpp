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
int mn=INT_MIN;
bool chk(int x)
{
    if(x<mn)
        return false;
    else return true;
}
bool bstchk(tnode *root)
{
    if(root==NULL)
        return true;

    if(bstchk(root->left))
    if(chk(root->data))
        {

    mn=root->data;
    if(bstchk(root->right))
        return true;
    }
    return false;
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
   if(bstchk(root))
    cout<<"ture";
   else cout<<"false";

}
