
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
int getCount(Node *head){
    int l=0;
    while(head!=NULL){
        l++;
        head=head->next;
    }
    return l;
}
  int main()  
{  
    
    Node* head = NULL;  
  
    push(&head, 1);  
    push(&head, 3);  
    push(&head, 1);  
    push(&head, 2);  
    push(&head, 1);  
  
    cout<<"count of nodes is "<< getCount(head);  
    return 0;  
}  

