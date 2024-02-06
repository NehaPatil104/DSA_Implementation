#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insertAtBeg(Node* &head, int data){

    Node* newnode = new Node(data);

    if(head == NULL){
        head = newnode;
        return;
    }

    newnode->next = head;
    head->prev = newnode;
    head = newnode;

}

void insertAtEnd(Node* &head, int data){
    Node* newnode = new Node(data);

    Node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->prev = temp;

}

int getLength(Node* &head){
    Node* temp = head;
    int cnt = 0;

    while(temp != NULL){
        cnt++;
        temp = temp->next;
    }

    return cnt;
}

void insertAtPos(Node* &head, int pos, int data){

    if(pos == 1){
        insertAtBeg(head, data);
    }
    else if(pos == getLength(head) + 1){
        insertAtEnd(head, data);
    }
    else{

        Node* newnode = new Node(data);
        int cnt = 1;
        Node* curr = head;
        
        while(cnt < pos - 1){
            curr = curr->next;
            cnt++;
        }

        newnode->next = curr->next;
        newnode->prev = curr;
        curr->next = newnode;
        newnode->next->prev = newnode;

    }
}

void deleteNode(Node* &head, int pos){

    if(pos == 1){
        Node* temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
    }
    else{
        int cnt = 1;

        Node *temp = head;

        while(cnt < pos){
            temp = temp->next;
            cnt++;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        delete temp;
    }
}

void print(Node* &head){
    Node* temp = head;

    cout<<"List-> ";

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    cout<<endl;
}


int main(){

    Node* head = NULL;

    insertAtBeg(head, 2);
    insertAtBeg(head, 11);
    insertAtBeg(head, 13);
    insertAtBeg(head, 8);

    print(head);

    insertAtEnd(head, 10);
    insertAtEnd(head, 44);
    insertAtEnd(head, 15);

    print(head);

    insertAtPos(head, 3, 50);

    print(head);

    insertAtPos(head, 9, 78);

    print(head);

    cout<<"Length-> "<<getLength(head)<<endl;

    deleteNode(head, 3);
    print(head);
    cout<<"Length-> "<<getLength(head)<<endl;

    deleteNode(head, 1);
    print(head);

    deleteNode(head, 7);
    print(head);

    return 0;
}