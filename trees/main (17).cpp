
#include <iostream>

using namespace std;
class node  
{  
    public: 
    int data;  
    node* left;  
    node* right;  
}; 

node* newNode(int data)  
{  
    node* Node = new node(); 
    Node->data = data;  
    Node->left = NULL;  
    Node->right = NULL;  
      
    return(Node);  
}

int maxDepth(node *root){
    if(root==NULL)
    return 0;
    if(root->left==NULL && root->right==NULL)
    return 1;
    int h=max(maxDepth(root->left),maxDepth(root->right))+1;
    return h;
}
int main()
{
     node *root = newNode(1);  
  
    root->left = newNode(2);  
    root->right = newNode(3);  
    root->left->left = newNode(4);  
    root->left->right = newNode(5);  
      
    cout << "Height of tree is " << maxDepth(root);  
    return 0; 
}
