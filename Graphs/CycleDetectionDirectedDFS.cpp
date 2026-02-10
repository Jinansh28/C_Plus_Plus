#include<bits/stdc++.h>
using namespace std;

class Graph {
    public:
    int V;
    list<int> *l;

    Graph(int V){
        this->V = V;
        this->l = new list<int > [V];
    }

    void addEdge(int u,int v){
        l[u].push_back(v);
    }
};

bool ans(Graph &g, vector<bool> &vis,vector<bool> &rec, int i){
    vis[i] = true;
    rec[i] = true;

    for(int j : g.l[i]){
        if(!vis[j]){
            if(ans(g,vis,rec,j)) return true;
        } else if(rec[j]){
            return true;
        }
    }
    rec[i] = false;
    return false;
}

bool cycleDetection(Graph &g){
    vector<bool> vis(g.V, false);
    vector<bool> rec(g.V, false);
    bool b = false;
    for (int i = 0; i < g.V; i++){
        if(vis[i] == false){
            b = ans(g,vis,rec,i);
            if(b) return b;
        }
    }
    return b;
};

int main(){
    Graph g(5);
    g.addEdge(1,0);
    g.addEdge(0,2);
    g.addEdge(2,3);
    g.addEdge(3,0);
    cout<<cycleDetection(g);
}