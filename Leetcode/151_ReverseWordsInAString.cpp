#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;


//O(n) space complexity & O(1) time complexity
// string reverseWords(string s) {
//     stack <string>m;
//     int i=0,j=0;
//     string a;
//     while(s[i]!='\0'){
//         if(s[i]!=' '){
//             a+=s[i];
//         }
//         if(s[i]==' ' && s[i+1]!=' ' && i<s.length()-1 && !a.empty()){
//             m.push(a);
//             a.clear();
//         }
//         i++;
//     }
//     m.push(a);
//     s.clear();
//     while(!m.empty()){
//         s+=m.top();
//         s+=" ";
//         m.pop();
//     }
//     s.erase(s.end()-1);
//     return s;
// }

//O(1) time and spcae complexity
string reverseWords(string s){
    reverse(s.begin(),s.end());
    string ans="",word="";
    for(int i=0;i<s.size();i++){
        if(s[i]!=' '){
            word+=s[i];
        }
        if(s[i]==' ' && i<s.size() && word.size()>0){
            reverse(word.begin(),word.end());
            ans+=" "+word;
            word.clear();
        }
    }
    if(!word.empty()){
        reverse(word.begin(),word.end());
        ans+=" "+word;
    }
    return ans.substr(1);
}

int main(){
    string s=" hello  world ";
    cout<<reverseWords(s);
}