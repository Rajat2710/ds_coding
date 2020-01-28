

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

void printMiddle(Node *head_r){
    Node *temp=head_r;
    int l=0;
    int mid=0;
   while(temp!=NULL){
       l++;
       temp=temp->next;
   }
  
   if(l%2!=0)
   mid=(l+1)/2;
   else
   mid=l/2+1;
   temp=head_r;
   for(int i=0;i<mid-1;i++) {
       temp=temp->next;
   }
   cout<<"the middle element is "<<temp->data<<endl;;
}

void printList(Node *head_r){
    Node *temp=head_r;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
Node* head = NULL;  
    int i;  
  
    for (i=5; i>0; i--)  
    {  
        push(&head, i);  
        printList(head);  
        printMiddle(head);  
    }  
  
}
