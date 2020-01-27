
#include <iostream>

using namespace std;
class Node {
    public:
    int data;
    Node *next;
};

void push(Node **head,int key){
    Node *new_n=new Node();
    new_n->data= key;
    new_n->next=*head;
    *head=new_n;
}
void deleteNode(Node **head,int pos){
    Node *temp=new Node();
    if(pos==0){
        *head=temp->next;
        free(temp);
        return;
    }
    
    for(int i=0;i<pos-1 && temp!=NULL;i++){
        temp=temp->next;
    }
     if(temp==NULL || temp->next==NULL)
    return;
    Node *next1=temp->next->next;
    free(temp->next);
    temp->next=next1;
}
void printList(Node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}
  int main()  
{  
    
    struct Node* head = NULL; 
  
    push(&head, 7); 
    push(&head, 1); 
    push(&head, 3); 
    push(&head, 2); 
    push(&head, 8); 
  
    puts("Created Linked List: "); 
    printList(head); 
    deleteNode(&head, 4); 
    puts("\nLinked List after Deletion at position 4: "); 
    printList(head); 
    return 0; 
}  

