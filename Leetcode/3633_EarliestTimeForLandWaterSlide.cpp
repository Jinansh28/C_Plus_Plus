#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int D=0;
        int ans=INT_MAX;
        for(int i=0;i<landStartTime.size();i++){
            D+=(landStartTime[i]+landDuration[i]);
            for(int j=0;j<waterStartTime.size();j++){
                int a=0,b=0;
                if(D<waterStartTime[j]){
                    a=(waterStartTime[j]-D+waterDuration[j]);
                    D+=a;
                }
                else{
                    b=waterDuration[j];
                    D+=b;
                }
                if(D<ans) ans=D;
                if(a>0) D-=a;
                else D-=b;
            }
            D=0;
        }
        for(int i=0;i<waterStartTime.size();i++){
            D+=(waterStartTime[i]+waterDuration[i]);
            for(int j=0;j<landStartTime.size();j++){
                int a=0,b=0;
                if(D<landStartTime[j]){
                    a=(landStartTime[j]-D+landDuration[j]);
                    D+=a;
                }
                else{
                    b=landDuration[j];
                    D+=b;
                }
                if(D<ans) ans=D;
                if(a>0) D-=a;
                else D-=b;
            }
            D=0;
        }
        return ans;
    }

int main(){
    vector<int> landStartTime={2,8};
    vector<int> landDuration={4,1};
    vector<int> waterStartTime={6};
    vector<int> waterDuration={3};
    cout<<earliestFinishTime(landStartTime,landDuration,waterStartTime,waterDuration);
}