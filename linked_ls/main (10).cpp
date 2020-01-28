

#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node *next;
};
/*void push(Node **head,int val){
    Node *new_n=new Node();
    new_n->data=val;
    new_n->next=*head;
    *head=new_n;
}*/
void removeDuplicates(Node *head){
    Node *temp=head;
    Node *temp1;
    while(temp!=NULL && temp->next!=NULL){
        temp1=temp;
        while(temp1->next!=NULL){
        if(temp->data==temp1->next->data) {
            Node *dup=temp1->next;
            temp1->next=temp1->next->next;
            free(dup);
        }
        else
        temp1=temp1->next;
        }
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
struct Node *start = newNode(10); 
    start->next = newNode(12); 
    start->next->next = newNode(11); 
    start->next->next->next = newNode(11); 
    start->next->next->next->next = newNode(12); 
    start->next->next->next->next->next = 
                                    newNode(11); 
    start->next->next->next->next->next->next = 
                                    newNode(10); 
  
    printf("Linked list before removing duplicates "); 
    printList(start); 
  
    removeDuplicates(start); 
  
    printf("\nLinked list after removing duplicates "); 
    printList(start); 
  
    return 0; 
}
