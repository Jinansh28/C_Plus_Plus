#include<iostream>
#include<stack>
using namespace std;

bool isValid(string s) {
    stack<char> a;
    
    for(int i=0;i<s.length();i++){
        if((s[i] == ')' && a.top() != '(') || (s[i] == '}' && a.top() != '{') || (s[i] == ']' && a.top() != '[') ) return false;

        if(s[i] == '[' || s[i] == '(' || s[i] == '{') a.push(s[i]);
        else a.pop();
    }
    return a.empty();
}

int main(){
    string s = "({})";
    cout<<isValid(s);
}