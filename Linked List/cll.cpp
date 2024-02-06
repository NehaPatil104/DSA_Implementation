#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
    
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertAtBeg(Node* &head, int data){
    Node* newnode = new Node(data);

    if(head == NULL){
        head = newnode;
        newnode->next = newnode;
    }
    else{
        Node* temp = head;

        while(temp->next != head){
            temp = temp->next;
        }

        temp->next = newnode;
        newnode->next = head;
        head = newnode;
    }
}

void insertAtEnd(Node* &head, int data){
    Node* newnode = new Node(data);

    if(head == NULL){
        head = newnode;
        newnode->next = newnode;
    }
    else{
        Node* temp = head;

        while(temp->next != head){
            temp = temp->next;
        }

        temp->next = newnode;
        newnode->next = head;
    }

}

void print(Node* &head){
    Node* temp = head;

    cout<<"List: ";
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp != head);

    cout<<endl;
}

int main(){

    Node* head = NULL;

    insertAtBeg(head, 10);
    insertAtBeg(head, 20);
    insertAtBeg(head, 30);

    print(head);

    insertAtEnd(head, 3);
    insertAtEnd(head, 8);
    insertAtEnd(head, 11);

    print(head);

    return 0;
}