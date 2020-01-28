

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
void lengthloop(Node *n) {
    Node *temp=n;
    int l=1;
    while(temp->next!=n){
    l++;
    temp=temp->next;
    }
    cout<<"length of loop "<<l<<endl;
}
  void startpt(Node *n, Node *head_r){
      Node *slow=head_r;
      Node *fast=n;
      Node *prev;
      while(slow!=fast){
          prev=fast;
          slow=slow->next;
          fast=fast->next;
      }
      cout<<"starting pt of loop is "<<slow->data<<endl;
      prev->next=NULL;
  }  
void detectAndRemoveLoop(Node *head) {
    Node *fast=head;
    Node *slow=head;
    
    while(fast && fast->next && slow){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            cout<<"loop detected"<<endl;
            lengthloop(fast);
            startpt(fast,head);
            break;
        }
    }
}

void printList(Node *head_r){
    Node *temp=head_r;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
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
struct Node* head = newNode(50); 
    head->next = newNode(20); 
    head->next->next = newNode(15); 
    head->next->next->next = newNode(4); 
    head->next->next->next->next = newNode(10); 
  
    head->next->next->next->next->next = head->next->next; 
  
    detectAndRemoveLoop(head); 
  
    cout << "Linked List after removing loop" << endl; 
  
    printList(head); 
  
    return 0; 
}
