#include <iostream>
using namespace std;

class Node{
    public: 
    int data;
    Node *nextNode;

    Node(int d){
        data = d;
        nextNode = NULL;
    }
    Node(){
        nextNode = NULL;
    }
};
// class Node{
//     private:
//     int data;
//     Node *nextNode;

//     public: 
//     Node(){
//         nextNode = NULL;
//     }
//     Node(int d){
//         data = d;
//         nextNode = NULL;
//     }
//     int getData(){
//         return data;
//     }
//     void setData(int d){
//         data = d;
//     }
//     Node* getNext(){
//         return nextNode;
//     }
//     void setNext(Node* n){
//         nextNode = n;
//     }   
// };

// Here we are using pass by reference to reflect changes on head. 
void append(Node* *head, int data){
    if(*head == NULL){
        Node* node = new Node(data);
        *head = node;
        return;
    }
    Node *temp = *head;
    while(temp->nextNode != NULL){
        temp = temp->nextNode;
    }
    Node *node = new Node(data);
    temp->nextNode = node;
}

void append2(Node* &head, int data){
    if(head == NULL){
        Node *nd = new Node(data);
        head = nd;
        return;
    }
    Node *nd = new Node(data);
    Node *temp = head;

    while(temp->nextNode != NULL){
        temp = temp->nextNode;
    }
    temp->nextNode = nd;

}

// Here we are using pointer to pointer for head, to reflect changes on head.
void push(Node* *head, int data){
    if(*head == NULL){
        Node *nd = new Node(data);
        *head = nd;
        return;
        
    }   
    Node *nd = new Node(data);
    nd->nextNode = *head;
    *head = nd;
}
void push2(Node* &head, int d){
    Node *nd = new Node(d);
    if(head == NULL){
        head = nd;
        return;
    }
    nd->nextNode = head;
    head = nd;

}

void showList(Node* head){
    while(head != NULL){
        cout<<head->data<<"--> ";
        head = head->nextNode;
    }

    
}

int main(){
    Node *head = NULL;
    append(&head, 10);
    append(&head,50);
    append(&head, 1000);
    append2(head, 89);
    push(&head,5);
    push2(head, 1);
    showList(head);

    return 0;
}