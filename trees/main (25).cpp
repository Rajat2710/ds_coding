
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

void levelorder(Node *root){
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
}
Node *sortedArrayToBST(int *arr,int l, int r){
    if(l>r)
    return NULL;
    int mid=(l+r)/2;
    Node *root=newNode(arr[mid]);
    root->left=sortedArrayToBST(arr, l, mid-1);
    root->right=sortedArrayToBST(arr, mid+1, r);
    return root;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};  
    int n = sizeof(arr) / sizeof(arr[0]);  
  
    Node *root = sortedArrayToBST(arr, 0, n-1);  
    cout << "levelOrder Traversal of constructed BST \n";  
    levelorder(root);  
  
    return 0; 
}