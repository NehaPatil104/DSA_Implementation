#include<iostream>
#include<queue>

using namespace std;

class Stack{
    public:
    queue<int> q1, q2;

    void push(int data){

        q2.push(data);

        while(!q1.empty()){
            int data = q1.front();
            q2.push(data);
            q1.pop();
        }

        while(!q2.empty()){
            int data = q2.front();
            q1.push(data);
            q2.pop();
        }
    }

    void pop(){
        if(q1.empty())
            cout<<"\nStack Underflow";
        else{
            cout<<"\nPopped Element==> "<<q1.front();
            q1.pop();
        }
    }

    void peek(){
        if(q1.empty())
            cout<<"\nStack Underflow";
        else
            cout<<"\nPeek Element==> "<<q1.front();
    }

    void print(){

        cout<<"\nStack==> ";

        while(!q1.empty()){
            int data = q1.front();
            cout<<data<<" ";
            q2.push(data);
            q1.pop();
        }

        while(!q2.empty()){
            int data = q2.front();
            q1.push(data);
            q2.pop();
        }
    }

};

int main(){

    Stack s;
    s.push(10);
    s.peek();
    s.push(20);
    s.peek();
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
    s.pop();
    return 0;
}