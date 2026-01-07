#include <bits/stdc++.h>
using namespace std;

int main() {
    int NC;
    int caseNo = 1;

    while (cin >> NC && NC != 0) {

        // adjacency list using map because node numbers are arbitrary
        map<int, vector<int>> adj;

        // read NC connections
        for (int i = 0; i < NC; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        // process queries
        while (true) {
            int start, TTL;
            cin >> start >> TTL;

            if (start == 0 && TTL == 0) break;

            // BFS from 'start'
            map<int, int> dist;
            queue<int> q;

            // initialize distances
            for (auto &p : adj) dist[p.first] = -1;

            if (adj.count(start)) {
                dist[start] = 0;
                q.push(start);
            }

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
            }

            // count unreachable nodes
            int unreachable = 0;

            for (auto &p : dist) {
                if (p.second == -1 || p.second > TTL) {
                    unreachable++;
                }
            }

            cout << "Case " << caseNo++ << ": " 
                 << unreachable 
                 << " nodes not reachable from node " << start
                 << " with TTL = " << TTL << ".\n";
        }
    }
    return 0;
}
