#include<bits/stdc++.h>
using namespace std;

class Graph {
    public:
    int V;
    list <int> *l;

    Graph(int V){
        this->V = V;
        l = new list<int> [V];
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
    }

    void printAdjList(){
        for(int i = 0 ;i< V; i++) {
            cout<<i<<":";
            for(int neigh: l[i] ){
                cout<<neigh<<" ";
            }
            cout<<endl;
        }
    }
};

void topologicalBFS(Graph g){
    vector<bool> vis(g.V, false);
    queue<int> q;
    vector<int> indegree(g.V, 0);

    for(int i = 0 ; i < g.V ; i++){
        for(int j : g.l[i]){
            indegree[j]++;
        }
    }
    for(int i = 0 ; i < g.V ; i++){ 
        if(indegree[i] == 0) {
            q.push(i); 
            vis[i] = true;
        }
    }
    vector<int> s;
    while(q.size() > 0){
        int curr = q.front();
        s.push_back(curr);
        q.pop();

        for(int i : g.l[curr]){
            indegree[i]--;
            if(indegree[i] == 0){
                q.push(i);
                vis[i] = true;
            }
        }
    }
    if(s.size() == g.V){
        for(int i : s) cout<<i<<" ";
    }
}

int main() {
    Graph g(6);

    g.addEdge(4,0);
    g.addEdge(5,0);
    g.addEdge(3,1);
    g.addEdge(4,1);
    g.addEdge(2,3);
    g.addEdge(5,2);

    topologicalBFS(g);
}