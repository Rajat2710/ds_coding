

#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node *next;
};
void push(Node **head,int val){
    Node *new_n=new Node();
    new_n->data=val;
    new_n->next=*head;
    *head=new_n;
}

void printMiddle(Node *head_r){
    Node *slow=head_r;
    Node *fast=head_r;
    
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    cout<<"The middle element is "<<slow->data<<endl;
}

void printList(Node *head_r){
    Node *temp=head_r;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
Node* head = NULL;  
    int i;  
  
    for (i=5; i>0; i--)  
    {  
        push(&head, i);  
        printList(head);  
        printMiddle(head);  
    }  
  
}
