#include<vector>
#include<unordered_map>
#include<unordered_set>
#include <iostream>
#include<queue>
using namespace std;

int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
    unordered_set<int> s;
    unordered_map<int,int> p;
    queue<int> q;
    int a = 0,ans = 0,c;
    for(int i = 0; i<arrivals.size();i++){
        int b = arrivals[i];
        if(a < w){
            a++;
        }
        else{
            c = q.front();
            q.pop();
            if(s.find(i-w) == s.end()){
                if(p[c]==1) p.erase(c);
                else p[c]--;
            }          
        }
        p[b]++;
            if(p[b]>m){
                ans++;
                p[b]--;
                s.insert(i);
            }
            q.push(b);
        }
    return ans;
}
    
    
int main() {
    vector<int> arrivals;
    for(int i=0; i<10000; i++) arrivals.push_back(i);
    int w = 10000, m = 1;
    cout<<minArrivalsToDiscard(arrivals,w,m);
    return 0;
}