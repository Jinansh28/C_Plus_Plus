#include<algorithm>
#include<iostream>
#include<cctype>
#include<string>
using namespace std;

bool isPalindrome(string s){
    int st=0,end=s.length()-1;
    while(st<end){
        if(!iswalnum(s[st])){
            st++;
            continue;
        }
        if(!iswalnum(s[end])){
            end--;
            continue;
        }
        if(tolower(s[st])!=tolower(s[end])){
            return false;
        }
        st++,end--;
    }
    return true;
}

int main() {
    string str="A man, a plan, a canAl :Panama";
    cout<<isPalindrome(str);
}