#include<iostream>
using namespace std;

int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = 0;
        while(numBottles > 0){
            if(numBottles >= numExchange) {
                ans += numExchange;
                numBottles -= numExchange;
                numBottles++;
                numExchange++; 
            } else {
                ans += numBottles;
                numBottles = 0;
            }
        }
        return ans;
    }

int main(){
    cout<<maxBottlesDrunk(10,3);
}