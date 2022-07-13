#include <iostream>
#include "node.h"
using namespace std;



class linkedList{
    public:
    Node *head = NULL;
    Node *tail = NULL;
    int length = 0;

    void append(int data){
        Node *nd = new Node(data);
        if(head == NULL){
            head = nd;
            tail = nd;
            length = 1;
            return;
        }
        Node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = nd;
        tail = nd;
        length++;
    }

    // Pushing a new element to the front.
    void push(int data){
        Node *nd = new Node(data);
        if(head == NULL){
            head = nd;
            tail = nd;
            length++;
            return;
        }
        nd->next = head;
        head = nd;
        length++;
    }

    // Inserting an element on the given position.
    void insert(int pos, int data){
        if(pos == 1){
            push(data);
            return;
        }
        
        Node *temp = head;
        Node *newnode = new Node(data); 
        int i = 1;
        while(i<pos - 1){
            temp = temp -> next;
            i++;
        }
        Node *temp2 = temp -> next;
        temp -> next = newnode;
        newnode -> next = temp2;
        length++;
        if(pos == length){
            tail = newnode;
        }
    }

    void insertAfter(int nd, int data){
        Node *newnd = new Node(data);
        Node *temp = head;

        while(temp->data != nd){
            temp = temp->next;
        }
        Node *temp2 = temp->next;
        temp -> next = newnd;
        newnd -> next = temp2;
        length++;
    }
    void printList(){
        Node *temp = head;
        while(temp != NULL){
            cout<<temp->data<<" --> ";
            temp = temp->next;
        }
        if(temp == NULL){
            cout<<"NULL\n";
        }
    }
    void printLength(){
        cout<<length;
    }
    void deleteNode(int d){
        Node *temp = head;
        if(temp == NULL){
            cout<<"Linked list is empty\n";
            length--;
            return;
        }
        if(temp->data == d){
            // if(temp ->next  )
            Node *nxt = temp -> next;
            delete temp;
            head = nxt;
            length--;
            return; 
        }


        while(temp -> next != NULL){
            if(temp -> next -> data == d){
                Node *sec = temp->next->next;
                delete temp -> next;
                temp->next = sec;
            }
            temp = temp -> next;
        }
        length--;   
    }


    
};



int main(){

    linkedList l1;
    l1.append(5);
    l1.append(10);
    l1.append(23);
    l1.insert(2,1000);
    l1.insertAfter(5,35);
    l1.printList();
    cout<<endl;
    l1.printLength();
    l1.deleteNode(5);
    cout<<endl;
    l1.printList();
    cout<<endl;
    l1.printLength();


    return 0;
}
