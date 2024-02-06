#include<iostream>
#include<stack>

using namespace std;

class Queue{
    public:
        stack<int> s1, s2;

        Queue(){
            stack<int> s1, s2;
        }

        void enqueue(int data){

            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }

            s2.push(data);

            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
        }

        void dequeue(){
            if(s1.empty())
                cout<<"\nQueue empty";
            else{
                cout<<"\nDeleted element ==> "<<s1.top();
                s1.pop();
            }
        }

        void peek(){
            if(s1.empty())
                cout<<"\nQueue empty";
            else{
                cout<<"\nPeek element ==> "<<s1.top();
            }
        }

        void display(){
            if(s1.empty())
                cout<<"\nQueue empty";
            else{
                cout<<"\nQueue ==> ";

                while(!s1.empty()){
                    cout<<s1.top()<<" ";
                    s2.push(s1.top());
                    s1.pop();
                }

                while(!s2.empty()){
                    s1.push(s2.top());
                    s2.pop();
                }
            }
        }
};

int main(){

    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.display();
    q.peek();

    q.dequeue();
    q.display();
    q.peek();
    q.dequeue();
    q.display();
    q.enqueue(100);
    q.display();
    return 0;
}