
#include <iostream>
#include<stack>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node *left;
    Node *right;
};
Node *newNode(int val){
    Node *node=new Node;
    node->data=val;
    node->left=node->right=NULL;
    return node;
}

Node *lca(Node *root,int n1,int n2){
    Node *curr=root;
    while(curr!=NULL){
        if(curr->data>n1 && curr->data>n2)
        curr=curr->left;
        else if(curr->data<n1 && curr->data<n2)
        curr=curr->right;
        else
        break;
    }
    return curr;
}
int main()
{
  Node *root = newNode(20);  
    root->left = newNode(8);  
    root->right = newNode(22);  
    root->left->left = newNode(4);  
    root->left->right = newNode(12);  
    root->left->right->left = newNode(10);  
    root->left->right->right = newNode(14);  
  
    int n1 = 10, n2 = 14;  
    Node *t = lca(root, n1, n2);  
    cout << "LCA of " << n1 << " and " << n2 << " is " << t->data<<endl;  
  
    n1 = 14, n2 = 8;  
    t = lca(root, n1, n2);  
    cout<<"LCA of " << n1 << " and " << n2 << " is " << t->data << endl;  
  
    n1 = 10, n2 = 22;  
    t = lca(root, n1, n2);  
    cout << "LCA of " << n1 << " and " << n2 << " is " << t->data << endl;  
    return 0;  
}