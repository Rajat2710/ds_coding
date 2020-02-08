
#include <iostream>
#include<queue>
using namespace std;

class BstNode{
    public:
    int data;
    BstNode *left;
    BstNode *right;
};

BstNode *newNode(int val){
    BstNode *node=new BstNode();
    node->data=val;
    node->left=node->right=NULL;
    return node;
}

BstNode *insert(BstNode *root,int val){
    if(root==NULL){
        root=newNode(val);
    }
    else if(val<=root->data){
        root->left=insert(root->left,val);
    }
    else
    root->right=insert(root->right,val);
    
    return root;
}

bool search(BstNode *root,int val){
    if(root==NULL)
    return false;
    if(root->data==val)
    return true;
    if(val<root->data)
    return search(root->left,val);
    if(val>root->data)
    return search(root->right,val);
}
int min(BstNode *root){
    if(root==NULL)
    return 0;
    while(root->left!=NULL){
        root=root->left;
    }
    return root->data;
}
int max(BstNode *root){
    if(root==NULL)
    return 0;
    while(root->right!=NULL){
        root=root->right;
    }
    return root->data;
}
void print(BstNode *root){
    if(root==NULL)
    return;
    queue<BstNode *> q;
    q.push(root);
    cout<<"level order traversal"<<endl;
    while(!q.empty()){
        BstNode *node=q.front();
        cout<<node->data<<" ";
        q.pop();
        if(node->left!=NULL)
        q.push(node->left);
        if(node->right!=NULL)
        q.push(node->right);
    }
    cout<<endl;
}
void inorder(BstNode *root){
   
   if(root==NULL)
   return;
   inorder(root->left);
   cout<<root->data<<" ";
   inorder(root->right);
}
void preorder(BstNode *root){
    
   if(root==NULL)
   return;
    cout<<root->data<<" ";
   preorder(root->left);
   preorder(root->right);
}
 void postorder(BstNode *root){
   
   if(root==NULL)
   return;
   postorder(root->left);
   postorder(root->right);
   cout<<root->data<<" ";
}
int main()
{
  BstNode *root=NULL;
  root = insert(root,4);
  root = insert(root,2);
  root = insert(root,6);
  root = insert(root,1);
  root = insert(root,3);
  root = insert(root,5);
  root = insert(root,7);
  cout<<search(root,7)<<endl;
  cout<<"minimum element "<<min(root)<<endl;
  cout<<"maximum element "<<max(root)<<endl;
  print(root);
   cout<<"inorder traversal"<<endl;
  inorder(root);
  cout<<endl<<"preorder traversal"<<endl;
  preorder(root);
   cout<<endl<<"postorder traversal"<<endl;
  postorder(root);
}
