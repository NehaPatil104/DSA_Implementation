#include<iostream>
using namespace std;

class Area{
    public:
        int length;
        int breadth;
        int height;

        int calculateArea(int length, int breadth){
            return length*breadth;
        }

        int calculateVolume(int length, int breadth, int height){
            return length*breadth*height;
        }
};

int main(){

    Area a1;
    cout<<"Area -> "<<a1.calculateArea(10,20)<<endl;
    cout<<"Volumne -> "<<a1.calculateVolume(10,5,5)<<endl;
    return 0;
}