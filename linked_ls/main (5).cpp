

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

int printNthFromLast(Node *head_r,int loc){
    Node *temp=head_r;
    int l=0;
    while(temp!=NULL) {
    l++;
    temp=temp->next;
    }
    for(int i=0;i<l-loc;i++){
       head_r=head_r->next;
    }
    return head_r->data;
}
int main()
{
    struct Node* head = NULL; 

    push(&head, 20); 
    push(&head, 4); 
    push(&head, 15); 
    push(&head, 35); 
  
   cout<< printNthFromLast(head, 3); 
    return 0; 
}
