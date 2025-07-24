#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string removeOccurrences(string s, string part) {
    int pos=s.find(part);
    while(pos<s.length() && s.length()>0){
        s.erase(pos,part.length());
        pos=s.find(part);
    }
    return s;
}

// string removeOccurrences(string s, string part) {
//     int i=0;
//     while(s[i]!='\0'){
//         string a=s.substr(i,part.length());
//         if(a==part){
//             s.erase(i,part.length());
//             i=-1;
//         }
//         i++;
//     }
//     return s;
// }


int main() {
    string s = "daabcbaabcbc", part = "abc";
    cout<<removeOccurrences(s,part);
    return 0;
}