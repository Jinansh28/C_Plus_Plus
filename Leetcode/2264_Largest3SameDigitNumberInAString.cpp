#include<iostream>
#include<string>
using namespace std;

string largestGoodInteger(string s) {
    int ans = -1;

    int freq = 0;
    char a = s[0],b;
    for(int i = 0;i < s.length(); i++){

        if(s[i] == a) freq++;
        else{
            freq = 1;
            a = s[i];
        }

        if(freq == 3){
            ans = max(ans,a-48);
            b = ans + 48;
        }

    }
    string st = "";
    if(ans != -1){
        st.push_back(b);
        st.push_back(b);
        st.push_back(b);
    }
    
    return st;
}

int main(){
    string s ="239248777";
    cout<<largestGoodInteger(s);
}