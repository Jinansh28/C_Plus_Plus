#include<iostream>
#include<vector>
#include<climits>
using namespace std;


int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
    int smallest=INT_MAX,b=0,D=INT_MAX;
    for(int i=0;i<landStartTime.size();i++){
        int a=landDuration[i]+landStartTime[i];
        if(a<smallest){ 
            smallest=a;
        }
    }
    for(int i=0;i<waterStartTime.size();i++){
        if(smallest<waterStartTime[i]){
            int a=waterDuration[i]+waterStartTime[i]-smallest;
            if(a<D) D=a;
        }
        else{
            if(waterDuration[i]<D) D=waterDuration[i];
        }
    }
    b=smallest+D;
    smallest=INT_MAX,D=INT_MAX;
    for(int i=0;i<waterStartTime.size();i++){
        int a=waterDuration[i]+waterStartTime[i];
        if(a<smallest){ 
            smallest=a;
        }
    }
    for(int i=0;i<landStartTime.size();i++){
        if(smallest<landStartTime[i]){
            int a=landDuration[i]+landStartTime[i]-smallest;
            if(a<D) D=a;
        }
        else{
            if(landDuration[i]<D) D=landDuration[i];
        }
    }
    if(b>smallest+D) b=smallest+D;
    return b;
}

int main(){
    vector<int> landStartTime={2,8};
    vector<int> landDuration={4,1};
    vector<int> waterStartTime={6};
    vector<int> waterDuration={3};
    cout<<earliestFinishTime(landStartTime,landDuration,waterStartTime,waterDuration);
}