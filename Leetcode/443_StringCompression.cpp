#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

//O(n) time O(m)space
// int compress(vector<char> &chars){
//     vector<char> ans(chars);
//     chars.clear();
//     chars.push_back(ans[0]);
//     int freq=1;
//     if(ans.size()>1){
//     for(int i=1;i<ans.size();i++){
//         if(ans[i]==ans[i-1]){
//             freq++;
//         }
//         else{
//             if(freq>1){
//                 string str=to_string(freq);
//                 for(char b:str){
//                     chars.push_back(b); 
//                 }
//             }
//             chars.emplace_back(ans[i]);
//             freq=1;
//         }
//     }
//     if(freq>1){
//         string str=to_string(freq);
//         for(char b:str){
//             chars.push_back(b); 
//         }
//     }
//     }
//     return chars.size();
// }

//O(n) time & O(1) space
int compress(vector<char> &chars){
    int n=chars.size(),idx=0;
    for(int i=0;i<n;){
        char a=chars[i];
        int count=0;
        while(i<n && chars[i]==a){
            count++;
            i++;
        }
        chars[idx++]=a;
        if(count>1){
            string str=to_string(count);
            for(char b:str){
                chars[idx++]=b; 
            }
        }
    }
    chars.erase(chars.begin()+idx,chars.end());
    return chars.size();
}

int main(){
    vector<char> chars={'a','a','b','b','c','c','c'};
    cout<<compress(chars);
}