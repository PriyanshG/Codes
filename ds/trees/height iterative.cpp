#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};
node* ins(node *root,int a)
{       node *newn=new node;
        newn->data=a;
        newn->left=newn->right=NULL;
        if(root==NULL)
        {
            root=newn;
        }
        else if(root->data<a)
        {
           root->right=ins(root->right,a);
        }
        else if(root->data>=a)
        {

            root->left=ins(root->left,a);
        }
    return root;
}
void print(node *root)
{
    if(root==NULL)
        return ;
    print(root->left);
    cout<<root->data<<" ";
    print(root->right);

}
int height(node *root)
{
    if(root==NULL)
        return 0;
    queue<node*> Q;
    Q.push(root);
int     height=0;int nc=0;
    while(1)
    {
        nc=Q.size();
        if(nc==0)
            return height;
        height++;
        while(nc)
        {

            node *temp=Q.front();
            Q.pop();
            if(temp->left!=NULL)
                Q.push(temp->left);
            if(temp->right!=NULL)
                Q.push(temp->right);
            nc--;
        }


    }
}
int main()
{int n,a;
    node *root;
    root=NULL;
    cout<<"Enter number of elements";
 /*   cin>>n;
    while(n--)
    {
        cin>>a;
        root=ins(root,a);
    }*///root=ins(root,5);
   // root=ins(root,4);
/*
    root=ins(root,6);
    root=ins(root,3);
    root=ins(root,1);
    root=ins(root,2);
*/
    print(root);
    if(root==NULL)
        cout<<0;
    else
    cout<<height(root)-1;
}
