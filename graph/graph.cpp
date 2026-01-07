#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    list<int> *l; // adjacency list

public:
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u); // for undirected graph
    }

    void printAdjList() {
        for(int i = 0; i < V; i++) {
            cout << i << " -> ";
            for(int nbr : l[i]) {
                cout << nbr << ", ";
            }
            cout << endl;
        }
    }

    // BFS Traversal
    // time complexity: O(V + E)
    // space complexity: O(V)
    void bfs() {
        queue<int> Q;
        vector<bool> visited(V, false);

        Q.push(0);
        visited[0] = true;

        cout << "BFS Traversal: ";

        while(Q.size() > 0) {
            int u = Q.front();
            Q.pop();
            cout << u << " ";

            for(int nbr : l[u]) {
                if(!visited[nbr]) {
                    Q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
        cout << endl;
    }

    // DFS Traversal
    // time complexity: O(V + E)
    // space complexity: O(V)
    void dfsHelper(int u, vector<bool> &visited) {
        visited[u] = true;
        cout << u << " ";

        for(int nbr : l[u]) {
            if(!visited[nbr]) {
                dfsHelper(nbr, visited);
            }
        }
    }

    void dfs() {
        int src = 0;
        cout << "DFS Traversal: ";
        vector<bool> visited(V, false);
        dfsHelper(src, visited);
        cout << endl;
    }

    // Check if graph is Bipartite
    // A graph is bipartite if vertices can be colored with 2 colors
    // such that no two adjacent vertices have the same color
    // time complexity: O(V + E)
    // space complexity: O(V)
    bool isBipartite() {
        vector<int> color(V, -1);
        queue<int> Q;

        Q.push(0);
        color[0] = 0;

        while(!Q.empty()) {
            int u = Q.front();
            Q.pop();

            for(int nbr : l[u]) {
                if(color[nbr] == -1) {
                    color[nbr] = 1 - color[u];
                    Q.push(nbr);
                } else if(color[nbr] == color[u]) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    g.printAdjList();
    g.bfs();
    g.dfs();

    if(g.isBipartite()) {
        cout << "Graph is Bipartite. Bi-colorable." << endl;
    } else {
        cout << "Graph is not Bipartite. Not bi-colorable." << endl;
    }
    return 0;
}

