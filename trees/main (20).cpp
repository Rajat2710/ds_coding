
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
Node *insertlevelorder(int *arr,Node *root,int i,int n){
    if(i<n){
        Node *temp=newNode(arr[i]);
        root=temp;
        root->left=insertlevelorder(arr,root->left,2*i+1,n);
        root->right=insertlevelorder(arr,root->right,2*i+2,n);
    }
    return root;
}
void inorderiter(Node *root){
    Node *current=root;
    stack<Node *>st;
    while(current!=NULL || st.empty()==false){
    while(current!=NULL){
        st.push(current);
        current=current->left;
    }
    current=st.top();
    st.pop();
    cout<<current->data<<" ";
    current=current->right;
    }
    cout<<endl;
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
void revlvlordr(Node *root){
     if(root==NULL)
    return;
    Node *curr=root;
    queue<Node *>q;
    stack<Node *>st;
    q.push(curr);
    while(!q.empty()){
        Node *node=q.front();
        st.push(node);
        q.pop();
        if(node->right!=NULL)
        q.push(node->right);
        if(node->left!=NULL)
        q.push(node->left);
        
    }
    while(!st.empty()){
        Node *tp=st.top();
        cout<<tp->data<<" ";
        st.pop();
    }
    cout<<endl;
}
void countandprhalfnodes(Node *root){
     if(root==NULL)
    return;
    Node *curr=root;
    queue<Node *>q;
    q.push(curr);
    int count=0;
    while(!q.empty()){
        Node *node=q.front();
        if((node->left==NULL && node->right!=NULL) || (node->right==NULL && node->left!=NULL)){
        cout<<node->data<<" ";
        count++;
        }
        q.pop();
        if(node->left!=NULL)
        q.push(node->left);
        if(node->right!=NULL)
        q.push(node->right);
    }
    cout<<" are the "<<count<<" half nodes"<<endl;
}
void countandprleafnodes(Node *root){
     if(root==NULL)
    return;
    Node *curr=root;
    queue<Node *>q;
    q.push(curr);
    int count=0;
    while(!q.empty()){
        Node *node=q.front();
        if(node->left==NULL && node->right==NULL){
        cout<<node->data<<" ";
        count++;
        }
        q.pop();
        if(node->left!=NULL)
        q.push(node->left);
        if(node->right!=NULL)
        q.push(node->right);
    }
    cout<<" are the "<<count<<" leaf nodes"<<endl;
}
void countandprfullnodes(Node *root){
     if(root==NULL)
    return;
    Node *curr=root;
    queue<Node *>q;
    q.push(curr);
    int count=0;
    while(!q.empty()){
        Node *node=q.front();
        if(node->left!=NULL && node->right!=NULL){
        cout<<node->data<<" ";
        count++;
        }
        q.pop();
        if(node->left!=NULL)
        q.push(node->left);
        if(node->right!=NULL)
        q.push(node->right);
    }
    cout<<" are the "<<count<<" full nodes"<<endl;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    Node *root=insertlevelorder(arr,root,0,n);
    cout<<"level order"<<endl;
    levelorder(root);
    cout<<"Inorder"<<endl;
    inorderiter(root);
    cout<<"reverse lvl ordr"<<endl;
    revlvlordr(root);
    cout<<"half node"<<endl;
    countandprhalfnodes(root);
    cout<<"leaf nodes"<<endl;
    countandprleafnodes(root);
    cout<<"full nodes"<<endl;
    countandprfullnodes(root);
}
