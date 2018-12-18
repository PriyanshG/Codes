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
int maxc(node *root)
{   if(root==NULL)
            return 0;
        int l=maxc(root->left);
        int r=maxc(root->right);
       return l>r?(l+1):(r+1);

}
    int height(node* root) {
        if(root==NULL)
            return 0;
        int a= maxc(root)-1;return a;
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
    }*/root=ins(root,5);
   /* root=ins(root,4);

    root=ins(root,6);
    root=ins(root,3);
    root=ins(root,1);
    root=ins(root,2);
*/
    print(root);
    cout<<height(root);
}
