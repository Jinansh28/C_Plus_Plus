#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
    int V;
    list<int> *l;

    Graph(int V){
        this->V = V;
        l = new list<int> [V];
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void printAdjList(){
        for(int i = 0; i < V; i++){
            cout<<i<<" : ";
            for(int neigh : l[i]){
                cout<<neigh<<" ";
            }
            cout<<endl;
        }
    }
};

bool cycleDetectionBFS(Graph g,int src,vector<bool> &vis){
    int parent = 0;
    queue<pair<int,int>> q;

    q.push({src,-1});
    vis[src] = true;

    while(q.size() > 0){    
        src = q.front().first;
        parent = q.front().second;

        q.pop();

        for(int i : g.l[src]){
            if(!vis[i]){
                vis[i] = true;
                q.push({i,src});
            }
            else if(i != parent){
                return true;
            }
        }
    }
    return false;
}

bool CycleDetection(Graph &g){
    vector<bool> vis(g.V,false);
    bool a = false;
    for(int i = 0; i < g.V ; i++){
        if(!vis[i]) a = cycleDetectionBFS(g,i,vis);
        if(a) return a;
    }
    return a;
}

int main(){
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(3,4);

    cout<<CycleDetection(g);
}