#include <bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        int n;
        cin >> n;
        if (!cin || n == 0) break;

        int l;
        cin >> l;

        vector<vector<int>> adj(n);
        for (int i = 0; i < l; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<int> color(n, -1);
        queue<int> q;
        bool isBipartite = true;

        // BFS from node 0 (graph is strongly connected)
        color[0] = 0;
        q.push(0);

        while (!q.empty() && isBipartite) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                } else if (color[v] == color[u]) {
                    isBipartite = false;
                    break;
                }
            }
        }

        if (isBipartite) cout << "BICOLORABLE.\n";
        else cout << "NOT BICOLORABLE.\n";
    }
    return 0;
}
