
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

bool search(Node *head,int val){
    while(head!=NULL){
        if(head->data==val)
        return true;
        head=head->next;
    }
}
  int main()  
{  
    
   Node* head = NULL;  
    int x = 21;  
    push(&head, 10);  
    push(&head, 30);  
    push(&head, 11);  
    push(&head, 21);  
    push(&head, 14);  
  
    search(head, 21)? cout<<"Yes" : cout<<"No";  
    return 0;  
}  

