#include<iostream>
using namespace std;

bool isPowerOfThree(int n) {
    if(n <= 0) return false;
    if(n == 1) return true;
    while(n > 1){
        if(n % 4 != 0) return false;
        n = n / 4;
    }
    return (n == 1);
}

int main(){
    cout<<isPowerOfThree(64);
}