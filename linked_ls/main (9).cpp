

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
void removeDuplicates(Node *head){
    Node *temp=head;
    Node *temp1;
    if(temp==NULL)
    return;
    while(temp->next!=NULL){
        if(temp->data==temp->next->data){
            Node *next1=temp->next->next;
             free(temp->next);
             temp->next=next1;
        }
        else
        temp=temp->next;
    }
}

void printList(Node *head_r){
    Node *temp=head_r;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
    cout<<endl;
}

Node * newNode(int key){
    Node *temp=new Node();
    temp->data=key;
    temp->next=NULL;
    return temp;
}
int main()
{
Node* head = NULL;  
     
    push(&head, 20);  
    push(&head, 13);  
    push(&head, 13);  
    push(&head, 11);  
    push(&head, 11);  
    push(&head, 11);                                      
  
    cout<<"Linked list before duplicate removal ";  
    printList(head);  
  
    removeDuplicates(head);  
  
    cout<<"\nLinked list after duplicate removal ";      
    printList(head);              
      
    return 0;  
}
