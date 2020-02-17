
#include <iostream>
#include <climits>
using namespace std;
class Node {
    public:
    int data;
    Node *left;
    Node *right;
};
int BST(Node *root,int min,int max){
    if(root==NULL)
    return 1;
    if(root->data>min && root->data<max && BST(root->left,min,root->data) && BST(root->right,root->data,max))
    return 1;
    else
    return 0;
}
int isBST(Node *root){
    return BST(root,INT_MIN,INT_MAX);
}
Node *newnode(int val){
    Node *node=new Node;
    node->data=val;
    node->left=node->right=NULL;
    return node;
}

int main()
{
 Node *root = newnode(4);  
    root->left = newnode(2);  
    root->right = newnode(5);  
    root->left->left = newnode(1);  
    root->left->right = newnode(3);  
      
    if(isBST(root))  
        cout<<"Is BST";  
    else
        cout<<"Not a BST";  
    return 0;  
}
