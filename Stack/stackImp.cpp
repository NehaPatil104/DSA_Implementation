#include<iostream>

using namespace std;

class Stack{
    public:

    int *arr;
    int size, top;

    Stack(){
        size = 100;
        arr = new int[size];
        top = -1;
    }

    void push(int data){
        if(top == size - 1)
            cout<<"\nStack overflow";
        else{
            ++top;
            arr[top] = data;
        }
    }

    void pop(){
        if(top == -1)
            cout<<"\nStack Underflow";
        else{
            cout<<"\nPopped Element==> "<<arr[top];
            top--;
        }
    }

    void peek(){
        if(top == -1){
            cout<<"\nStack Underflow";
        } 
        else{
           cout<<"\nPeek==>"<<arr[top];
        }
    }

    void print(){

        cout<<"\nStack==> ";
        for(int i = top; i >= 0; i--)
            cout<<arr[i]<<" ";
    }

};

int main(){

    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.print();

    s.pop();
    s.print();
    s.peek();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    return 0;
}