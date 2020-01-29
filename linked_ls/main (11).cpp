
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

void swapNodes(Node **st,int n1,int n2) {
    Node *swap1=*st;
    Node *swap2=*st;
    Node *prev1,*prev2;
    if (n1==n2) return;
    for(int i=0;i<n1-1;i++) {
        prev1=swap1;
        swap1=swap1->next;
    }
    for(int i=0;i<n2-1;i++) {
        prev2=swap2;
        swap2=swap2->next;
    }
    if (swap1 == NULL || swap2 == NULL)  
    return;
   
    if(prev2!=NULL)
    prev2->next=swap1;
    else
    *st=swap1;
   
    if(prev1!=NULL)
    prev1->next=swap2;
    else
    *st=swap2;
    
     Node *temp=swap1->next;
     swap1->next=swap2->next;
    swap2->next=temp;
}
int main()
{
    Node *start = NULL;  
  
    push(&start, 7);  
    push(&start, 6);  
    push(&start, 5);  
    push(&start, 4);  
    push(&start, 3);  
    push(&start, 2);  
    push(&start, 1);  
  
    cout << "Linked list before calling swapNodes() ";  
    printList(start);  
  
    swapNodes(&start, 3, 4);  
  
    cout << "\nLinked list after calling swapNodes() ";  
    printList(start);  
  
    return 0; 
}
