#include<bits/stdc++.h>
using namespace std;

class Graph{
    public: 
    int V;
    list <int> *l;

    Graph(int V){
        this->V = V;
        l = new list<int> [V];
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void printAdjList(){
        for(int i = 0 ; i < V ; i++){
            cout<<i<<" : ";
            for(int neigh : l[i]){
                cout<<neigh<<" ";
            }
            cout<<endl;
        }
    }
};

void BFS(Graph g){
    queue <int> q;
    vector<bool> vis(g.V, false);

    q.push(0);
    vis[0] = true;

    while(q.size() > 0){
        int src = q.front();
        q.pop();
        cout<<src<<" ";

        for(int i : g.l[src]){
            if(!vis[i]){
                vis[i] = true;
                q.push(i);
            }
        }
    }
}

void DFS(int u,vector<bool> &vi,Graph g){
    cout<<u<<" ";
    vi[u] = true;
    for(int i : g.l[u]){
        if(!vi[i]){
            vi[i] = true;
            DFS(i,vi,g);
        }
    }
    return;
}

int main(){
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);

    g.printAdjList();

    cout<<"BFS : ";
    BFS(g);
    cout<<endl<<"DFS : ";

    vector<bool> vi(g.V,false);

    for(int i = 0 ; i < g.V ; i++){
        if(!vi[i]){
            DFS(i,vi,g);
        }
    }
    
}