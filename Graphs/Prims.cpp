#include<bits/stdc++.h>
using namespace std;

void Prims(vector<vector<pair<int,int>>> &g, int &V){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<bool> set(V, false);
    pq.push({0,0});

    int mst = 0;
    while(pq.size() > 0){
        int b = pq.top().second;
        int a = pq.top().first;
        pq.pop();
        if(set[a]) continue;
        set[a] = true;
        mst += b;

        for(auto &i : g[a]){
            int c = i.first;
            int d = i.second;
            if(!set[d]) pq.push({c, d});
        }
    }
    cout<<mst;
}

int main(){
    int V = 4;
    vector<vector<pair<int,int>>> g(V);

    g[0].push_back({1,10});
    g[1].push_back({0,10});
    
    g[0].push_back({3,30});
    g[3].push_back({0,30});

    g[0].push_back({2,15});
    g[2].push_back({0,15});

    g[1].push_back({3,40});
    g[3].push_back({1,40});

    g[2].push_back({3,50});
    g[3].push_back({2,50});

    Prims(g, V);
    return 0;
}