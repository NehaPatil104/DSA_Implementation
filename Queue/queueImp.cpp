#include<iostream>

using namespace std;

class Queue{
    public:
        int size = 100;
        int *arr = new int[size];
        int front, rear;

        Queue(){
            front = -1;
            rear = -1;
        }

        void enqueue(int data){

            if(rear == size - 1)
                cout<<"\nQueue full";
            else{
                if(front == -1)
                    front = 0;
                
                rear++;
                arr[rear] = data;
            }
        }

        void dequeue(){
            if(front == -1)
                cout<<"\nQueue empty";
            else{
                cout<<"\nDeleted element ==> "<<arr[front];
                front++;
            }
        }

        void peek(){
            if(front == -1)
                cout<<"\nQueue empty";
            else{
                cout<<"\nFront ==> "<<arr[front];
            }
        }

        void display(){
            if(front == -1)
                cout<<"\nQueue empty";
            else{
                cout<<"\nQueue ==> ";
                for(int i = front; i <= rear; i++)
                    cout<<arr[i]<<" ";
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
    return 0;
}