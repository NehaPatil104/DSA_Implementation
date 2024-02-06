#include<iostream>
#include<string>

using namespace std;

bool isPalindrome(string s, int start, int end){
    if(start > end)
        return true;
    
    if(s[start] == s[end])
        return isPalindrome(s,start+1, end-1);

    return false;
}

int main(){

    string s;
    cin>>s;

    cout<<"isPalindrome ? -> "<<isPalindrome(s, 0, s.length() -1);

    return 0;
}