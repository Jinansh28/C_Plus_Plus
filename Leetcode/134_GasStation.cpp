#include <iostream>
#include<vector>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalgas = 0, totalcost = 0;
        for(int i = 0 ;i < n; i++){
            totalcost += cost[i];
            totalgas += gas[i];
        }
        if(totalgas < totalcost) return -1;
        int currgas = 0, start = 0;
        for(int  i = 0 ;i < n ; i++){
            currgas = currgas + gas[i] - cost[i];
            if(currgas < 0){
                start = i;
                currgas = 0;
            }
        }
        return start;
    }

int main() {
    vector<int> cost = {2,3,4}, gas = {3,4,3};
    cout<<canCompleteCircuit(gas,cost);
    return 0;
}