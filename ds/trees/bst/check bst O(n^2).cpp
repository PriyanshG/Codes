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
bool lsbstck(tnode *nod,int x)
{
if(nod==NULL)
        return true;
    if(nod->data<=x)
        return true;
    return false;

}
bool rsbstck(tnode *nod,int x)
{if(nod==NULL)
        return true;
    if(nod->data>x)
        return true;
    return false;

}
bool bstchk(tnode *root)
{
    if(root==NULL)
        return true;
    if(lsbstck(root->left,root->data))
    {
        if(bstchk(root->left))



    if(rsbstck(root->right,root->data))
    {
        if(bstchk(root->right))
        return true;


    }}
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
