#include<iostream> 
using namespace std; 
struct node 
{ 
	struct node *left, *right; 
	int key; 
}; 
node* newNode(int key) 
{ 
	node *temp = new node; 
	temp->key = key; 
	temp->left = temp->right = NULL; 
	return temp; 
} 
void printSingles(struct node *root) 
{ 
    if(root==NULL)
    return;
    if(root->left!=NULL && root->right!=NULL){
        printSingles(root->left);
        printSingles(root->right);
    }
    else if(root->left!=NULL){
        cout<<root->left->key<<" ";
        printSingles(root->left);
    }
    else if(root->right!=NULL){
        cout<<root->right->key<<" ";
        printSingles(root->right);
    }
} 
int main() 
{ 
	node *root = newNode(1); 
	root->left = newNode(2); 
	root->right = newNode(3); 
	root->left->right = newNode(4);
  root->left->right->left = newNode(7);
  root->left->right->right = newNode(8);
	root->right->left = newNode(5); 
	root->right->left->left = newNode(6); 
	printSingles(root); 
	return 0; 
} 