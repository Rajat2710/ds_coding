
#include <iostream>

using namespace std;
class Node {
    public:
    int data;
    Node *next;
};

void at_end(Node **head_r,int key){
    Node *new_n=new Node();
    new_n->data=key;
    new_n->next=NULL;
    
    if(*head_r==NULL){
    *head_r=new_n;
    return;
    }
    
    Node *end=*head_r;
    while(end->next!=NULL){
        end=end->next;
    }
    end->next=new_n;
}
void at_st(Node **head,int key){
    Node *new_n=new Node();
    new_n->data= key;
    new_n->next=*head;
    *head=new_n;
}

void insertAfter(Node *prev,int val){
    Node *new_n = new Node();
    new_n->data=val;
    new_n->next=prev->next;
    prev->next=new_n;
}
void printList(Node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}
  int main()  
{  
    
    Node* head = NULL;  
      
     
    at_end(&head, 6);  
   
    at_st(&head, 7);  
  
    at_st(&head, 1);  
   
    at_end(&head, 4);  
      
  
    insertAfter(head->next, 8);  
      
    cout<<"Created Linked list is: ";  
    printList(head);  
      
    return 0;  
}  

