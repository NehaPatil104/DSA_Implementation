#include<iostream>

using namespace std;

int sumOfN(int i, int sum){
    if(i < 1)
        return sum;
    
    sum += i;

    return sumOfN(i-1, sum);
}

int functional(int n){
    if(n == 0)
        return 0;
    
    return n + functional(n-1);
}

int main(){

    int n;
    cin>>n;

    cout<<"Parameterized Sum: "<<sumOfN(n , 0)<<endl;
    cout<<"Functional Sum :"<<functional(n)<<endl;

    return 0;
}