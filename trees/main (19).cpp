
#include <iostream>
#include <climits>
using namespace std;
class Node {
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
Node *insert(Node *root,int val){
    if(root==NULL)
    return newNode(val);
    if(root->data>val)
    root->left=insert(root->left,val);
    else
    root->right=insert(root->right,val);
    return root;
}
Node *findMin(Node *root){
    Node *temp=root;
   while(temp->left!=NULL)
   temp=temp->left;
    return temp;
}
Node *deleteNode(Node *root,int val){
    if(root==NULL)
    return root;
    else if(root->data>val)
    root->left=deleteNode(root->left, val);
    else if(root->data<val)
    root->right=deleteNode(root->right, val);
    else{
        if(root->left==NULL && root->right==NULL){
        delete root;
        root=NULL;
        }
        else if(root->left==NULL){
            Node *temp=root;
            root=root->right;
            delete temp;
        }
        else if(root->right==NULL){
            Node *temp=root;
            root=root->left;
            delete temp;
        }
        else{
            Node *temp=findMin(root->right);
            root->data=temp->data;
            root->right=deleteNode(root->right,temp->data);
        }
    }
    return root;
}
void inorder(Node *root){
    if (root != NULL) { 
        inorder(root->left); 
       cout<<root->data<<" ";
        inorder(root->right); 
    } 
}
int main()
{
 Node* root = NULL; 
    root = insert(root, 50); 
    root = insert(root, 30); 
    root = insert(root, 20); 
    root = insert(root, 40); 
    root = insert(root, 70); 
    root = insert(root, 60); 
    root = insert(root, 80); 
  
    printf("Inorder traversal of the given tree \n"); 
    inorder(root); 
  
    printf("\nDelete 20\n"); 
    root = deleteNode(root, 20); 
    printf("Inorder traversal of the modified tree \n"); 
    inorder(root); 
  
    printf("\nDelete 30\n"); 
    root = deleteNode(root, 30); 
    printf("Inorder traversal of the modified tree \n"); 
    inorder(root); 
  
    printf("\nDelete 50\n"); 
    root = deleteNode(root, 50); 
    printf("Inorder traversal of the modified tree \n"); 
    inorder(root); 
  
    return 0; 
}
