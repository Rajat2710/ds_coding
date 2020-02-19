
#include <iostream>
#include<stack>
#include<queue>
#include<vector>
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
Node *insertlevelorder(int *arr,Node *root,int i,int n){
    if(i<n){
        Node *temp=newNode(arr[i]);
        root=temp;
        root->left=insertlevelorder(arr,root->left,2*i+1,n);
        root->right=insertlevelorder(arr,root->right,2*i+2,n);
    }
    return root;
}

/*void levelorder(Node *root){
    if(root==NULL)
    return;
    Node *curr=root;
    queue<Node *>q;
    q.push(curr);
    while(!q.empty()){
        Node *node=q.front();
        cout<<node->data<<" ";
        q.pop();
        if(node->left!=NULL)
        q.push(node->left);
        if(node->right!=NULL)
        q.push(node->right);
    }
    cout<<endl;
}*/
int height(Node *root){
    if(root==NULL)
    return 0;
    if(root->left==NULL && root->right==NULL)
    return 1;
    else{
        return max(height(root->left),height(root->right))+1;
    }
}
void lvlordr(Node *root,int i,bool itr){
    Node *curr=root;
    if(curr==NULL)
    return;
    if(i==1)
    cout<<curr->data<<" ";
    else if(i>1){
    if(!itr){
        lvlordr(curr->right,i-1,itr);
       lvlordr(curr->left,i-1,itr);
    }
    else{
        lvlordr(curr->left,i-1,itr);
       lvlordr(curr->right,i-1,itr);
    }
    }
    else{}
}
void levelorderspiral(Node *root){
   int h=height(root);
   bool itr=false;
   for(int i=1;i<=h;i++){
       lvlordr(root,i,itr);
       itr=!itr;
       cout<<endl;
   }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};  
    int n = sizeof(arr) / sizeof(arr[0]);  
  
    Node *root = insertlevelorder(arr,root,0, n);  
  cout << "levelOrder Traversal of constructed BST in spiral \n";  
    levelorderspiral(root); 
    return 0; 
}