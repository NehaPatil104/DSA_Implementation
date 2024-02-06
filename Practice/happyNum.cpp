#include<iostream>
#include<set>
using namespace std;

int findsquaresum(int n){
    int sum = 0;

    while(n != 0){
        int square = (n%10)*(n%10);
        sum += square;
        n /= 10;
    }
    return sum;
}

int main(){

    int n;
    cin>>n;
    set<int> s;
    while(true){
        n = findsquaresum(n);

        if(n==1){
            cout<<"Happy Number";
            break;
        }
        if(s.find(n) != s.end()){
            cout<<"Not happy number";
            break;
        }
        s.insert(n);
    }
    return 0;
}