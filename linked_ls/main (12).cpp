
#include <iostream>

using namespace std;
class Node {
    public:
    int data;
    Node *next;
};

void push(Node **head_r,int val) {
    Node *new_n= new Node();
    new_n->data=val;
    new_n->next=*head_r;
    *head_r=new_n;
}

void printList(Node *head_r) {
    Node *temp=head_r;
    while(temp!=NULL) {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
}
void rev(Node **head){
    Node *curr=*head;
    Node *prev=NULL,*next1=NULL;
    while(curr!=NULL) {
        next1=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next1;
    }
    *head=prev;
}
int main()
{
   Node* start = NULL; 
  
    push(&start, 5); 
    push(&start, 4); 
    push(&start, 3); 
    push(&start, 2); 
    push(&start, 1); 
  
    cout << "Linked list "
         << "before reverse\n"; 
    printList(start); 
  
   rev(&start); 
  
    cout << "\nLinked list "
         << "after reverse\n"; 
    printList(start); 
  
    return 0; 
}
