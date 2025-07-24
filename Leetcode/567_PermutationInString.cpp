#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

// bool checkInclusion(string s1, string s2) {
//     string s3=s1;
//     while(1){
//         if(s2.find(s1)<s2.length()){
//             return true;
//         }
//         s3=next_permutation(s3.begin(),s3.end());
//         if(s3==s1) break;
//     }
//     return false;     
// }


//O(m*n)
// bool checkInclusion(string s1,string s2){
//     if(s1.length()>s2.length()) return false;
//     vector<int> v1(26,0);
//     int a=s1.length();
//     for(int i=0;i<a;i++){
//         v1[s1[i]-'a']++;
//     }
//     for(int i=0;i<s2.length()-a+1;i++){
//         string s3=s2.substr(i,a);
//         vector<int> v2(26,0);
//         for(int j=0;j<a;j++){
//             v2[s3[j]-'a']++;
//         }
//         if(v1==v2) return true;
//     }
//     return false;
// }


//O(m)
bool checkInclusion(string s1,string s2){
    if(s1.length()>s2.length()) return false;
    vector<int> v1(26,0),v2(26,0);
    int a=s1.length(),b=s2.length();
    for(int i=0;i<a;i++){
        v1[s1[i]-'a']++;
    }
    for(int i=0;i<b;i++){
        v2[s2[i]-'a']++;
        if(i>=a){
            v2[s2[i-a]-'a']--;
        }
        if(v1==v2) return true;
    }
    return false;
}

int main(){
    string s1 = "ab", s2 = "eidbaooo";
    cout<<checkInclusion(s1,s2);
    return 0;
}