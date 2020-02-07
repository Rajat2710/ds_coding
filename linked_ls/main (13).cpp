
#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node *next;
};
void push(Node **head,int val){
    Node *newNode=new Node();
    newNode->data=val;
    newNode->next=*head;
    *head=newNode;
}
void reversell(Node **head){
    Node *prev=NULL;
    Node *curr=*head;
    while(curr!=NULL){
        Node *temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    *head=prev;
}
void traverse(Node *head1){
    if(head1==NULL){
        cout<<endl;
    return;
    }
    cout<<head1->data<<" ";
    traverse(head1->next);
}

void revtrav(Node *head1){
    if(head1==NULL)
    return;
    
    revtrav(head1->next);
    cout<<head1->data<<" ";
}

int main()
{
    Node *head=NULL;
    for(int i=5;i>=1;i--)
    push(&head,i);
    reversell(&head);
    traverse(head);
    revtrav(head);
}
