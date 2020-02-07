
#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node *prev;
};
void push(Node **head,int val){
    Node *new_node=new Node();
    new_node->data=val;
     new_node->next=*head;
    new_node->prev=NULL;
    if(*head!=NULL){
     (*head)->prev=new_node;   
    }
    *head=new_node;
}
void insertAfter(Node *pre,int val){
    if(pre==NULL){
        cout<<"prev is null";
        return;
    }
    Node *new_node=new Node();
    new_node->data=val;
    new_node->next=pre->next;
    pre->next=new_node;
    new_node->prev=pre;
    if(new_node->next!=NULL)
    new_node->next->prev=new_node;
}
void append(Node **head,int val){
    Node *new_node=new Node();
    new_node->data=val;
    new_node->next=NULL;
    if(*head==NULL){
        new_node->prev=NULL;
        *head=new_node;
        return;
    }
    Node *temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    new_node->prev=temp;
    temp->next=new_node;
}
void printList(Node *head){
    Node *last=new Node();
    while(head!=NULL){
        cout<<head->data<<" ";
       last=head;
        head=head->next;
    }
    cout<<endl;
    cout<<"traverse in reverse"<<endl;
     while(last!=NULL){
        cout<<last->data<<" ";
       // Node *last=head;
        last=last->prev;
    }
}
int main()
{
    Node* head = NULL;  
  
    append(&head, 6);  
  
    push(&head, 7);  
  
    push(&head, 1);  
  
    append(&head, 4);  
 
    insertAfter(head->next, 8);  
  
    cout << "Created DLL is: ";  
    printList(head);  
  
    return 0;  
}
