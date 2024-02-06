#include <iostream>
using namespace std;

string isPalin(string s){
    for(int i = 0; i < s.length()/2; i++){
        if(s[i] != s[s.length()-i-1])
            return "NO";
    }
    return "YES";
}
int main() {
    string s;
    cin>>s;

    cout<<isPalin(s);
    return 0;
}
