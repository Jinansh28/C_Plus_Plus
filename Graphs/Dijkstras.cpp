#include<bits/stdc++.h>
using namespace std;

class Edge {
    public:
    int v;
    int wt;

    Edge(int v, int wt){
        this->v = v;
        this->wt = wt;
    }
};

void dijsktra(vector<vector<Edge>> g, int src, int V){
    vector<int> dis(V, INT_MAX);
    dis[src] = 0;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,src});

    while(pq.size() > 0){
        int b = pq.top().second;
        pq.pop();

        for(Edge e : g[b]){
            if(e.wt + dis[b] < dis[e.v]) {
                dis[e.v] = e.wt + dis[b];
                pq.push({dis[e.v], e.v});
            }
        }
    }

    for(int i : dis)cout<<i<<" ";
}

int main(){
    int V = 6;
    vector<vector<Edge>> g(V);

    g[0].push_back(Edge(1,2));
    g[0].push_back(Edge(2,4));

    g[1].push_back(Edge(2,1));
    g[1].push_back(Edge(3,7));

    g[2].push_back(Edge(4,3));

    g[3].push_back(Edge(5,1));

    g[4].push_back(Edge(5,5));
    g[4].push_back(Edge(3,2));

    dijsktra(g, 0, V);
    return 0;
}