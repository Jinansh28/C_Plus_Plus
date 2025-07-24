#include<iostream>
#include<vector>
using namespace std;

vector<char> reverseString(vector<char>& s) {
    int st=0,end=s.size()-1;
    while(st<=end){
        swap(s[st++],s[end--]);
    }
}
