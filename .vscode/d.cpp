// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include<string>
using namespace std;


    string majorityFrequencyGroup(string s) {
        vector<int> p(26,0),r(s.length(),0);
        for(int i=0; i< s.length() ; i++){
            p[s[i]-97]++;
        }
        for(auto i: p)cout<<i<<" ";
        cout<<endl;
        for(int i =0; i<26;i++){
            if(p[i]!= 0){
                r[p[i]]++;
            }
        }
        for(auto i: r)cout<<i<<" ";
        cout<<endl;
        int maxm = 0;
        for(int i = 0;i<s.length();i++){
            maxm = max(maxm,r[i]);
        }
        cout<<maxm<<endl;
        int maxelement = 0;
        for(int i = 0;i<s.length();i++){
            if(r[i] == maxm){
                maxelement = max(maxelement,i);
            }
        }
        cout<<maxelement<<endl;
        string ans ="";
        for(int i = 0;i<26;i++){
            char a = 0;
            if(p[i]==maxelement){
                a+=97+i;
                ans+=a;
            }
        }
        return ans;
    }



int main() {
    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa©leetcode";
    cout<<majorityFrequencyGroup(s);
    return 0;
}