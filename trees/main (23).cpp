
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
/*void inorderiter(Node *root){
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
}*/
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
/*int height(Node *root){
    if(root==NULL)
    return 0;
    Node *curr=root;
    if(root->left==NULL && root->right==NULL)
    return 1;
    else{
     return max(height(root->left),height(root->right))+1;   
    }
}
void printlvl(Node *root,int i){
    if(root==NULL)
    return;
    if(i==1){
        cout<<root->data<<" ";
    }
    if(i>1){
        printlvl(root->left,i-1);
        printlvl(root->right,i-1);
    }
}
void lvlbylvl(Node *root){
    int h=height(root);
    for(int i=1;i<=h;i++){
        printlvl(root,i);
        cout<<endl;
    }
}*/
void avglvlqueue(Node *root){
    Node *curr=root;
    queue<Node *>q;
    q.push(curr);
    while(!q.empty()){
    int size=q.size();
    int c=0;
    int sum=0;
    while(size>0){
        Node *tp=q.front();
       // cout<<tp->data<<" ";
       sum=sum+tp->data;
       c++;
        q.pop();
        if(tp->left!=NULL)
        q.push(tp->left);
        if(tp->right!=NULL)
        q.push(tp->right);
        size--;
    }
    float avg=sum*1.0/c;
    cout<<avg;
    cout<<endl;
    }
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
  /*  cout<<"Inorder"<<endl;
    inorderiter(root);
    cout<<"print tree lvl by lvl"<<endl;
    lvlbylvl(root);*/
    cout<<"avg of every lvl"<<endl;
    avglvlqueue(root);
}