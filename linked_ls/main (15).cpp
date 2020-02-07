
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

void printList(Node *head){
    Node *last=new Node();
    while(head!=NULL){
        cout<<head->data<<" ";
       last=head;
        head=head->next;
    }
}
void deleteNode(Node **head,Node *del){
    if(*head==NULL)
    return;
    if(del==NULL)
    return;
    if(del==*head)
    *head=del->next;
    if(del->next!=NULL)
    del->next->prev=del->prev;
    if(del->prev!=NULL)
    del->prev->next=del->next;
    free(del);
}
int main()
{
  Node* head = NULL;  
 
    push(&head, 2);  
    push(&head, 4);  
    push(&head, 8);  
    push(&head, 10);  
  
    cout << "Original Linked list ";  
    printList(head);  
  
    deleteNode(&head, head); 
    deleteNode(&head, head->next); 
    deleteNode(&head, head->next); 
  
    cout << "\nModified Linked list ";  
    printList(head);  
  
    return 0; 
}
