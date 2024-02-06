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

void insertAtBeg(Node * &head, int data){
    Node * newnode = new Node(data);

    if(head != NULL){
        newnode->next = head;
    }

    head = newnode;
}

void insertAtEnd(Node* &head, int data){
    Node* newnode = new Node(data);
    Node* temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;

}

void insertAtPos(Node* &head, int data, int pos){
    Node* newnode = new Node(data);
    Node* temp = head;
    int cnt = 1;

    while(cnt < pos - 1){
        temp = temp->next;
        cnt++;
    }

    newnode->next = temp->next;
    temp->next = newnode;

}

void deleteNode(Node* &head, int pos){
    
    if(pos == 1){
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    else{

        int cnt = 1;
        Node* curr = head;
        Node* prev = NULL;
        
        while(cnt < pos){
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;
        delete curr;
    }
}

void print(Node* &head){
    Node* temp = head;
    cout<<"List -> ";
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){

    Node * head = NULL;

    insertAtBeg(head, 10);
    insertAtBeg(head, 20);
    insertAtBeg(head, 100);
    insertAtBeg(head, 33);

    print(head);

    insertAtEnd(head, 409);
    insertAtEnd(head, 34);

    print(head);

    insertAtPos(head, 104, 2);
    insertAtPos(head, 4, 5);

    print(head);

    deleteNode(head, 1);
    print(head);
    deleteNode(head, 4);
    print(head);
    deleteNode(head, 6);
    print(head);
    deleteNode(head, 5);
    print(head);
    return 0;
}