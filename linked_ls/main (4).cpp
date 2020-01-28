

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

int GetNth(Node *head_r,int loc){
    for(int i=0;i<loc;i++){
        head_r=head_r->next;
    }
    return head_r->data;
}
int main()
{
    Node* head = NULL;  
 
    push(&head, 1);  
    push(&head, 4);  
    push(&head, 1);  
    push(&head, 12);  
    push(&head, 1);  
  
    cout << "Element at index 3 is " << GetNth(head, 3);  
    return 0; 
}
