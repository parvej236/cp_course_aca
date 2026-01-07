#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N + 1);

    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }

    vector<long long> dist(N + 1, LLONG_MAX);
    vector<long long> ways(N + 1, 0);

    queue<int> q;

    dist[1] = 0;
    ways[1] = 1;
    q.push(1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            // First time discovering this node (shorter path)
            if (dist[v] == LLONG_MAX) {
                dist[v] = dist[u] + 1;
                ways[v] = ways[u];
                q.push(v);
            }
            // Found another shortest path
            else if (dist[v] == dist[u] + 1) {
                ways[v] = (ways[v] + ways[u]) % MOD;
            }
        }
    }

    if (dist[N] == LLONG_MAX) {
        cout << 0 << "\n";
    } else {
        cout << ways[N] % MOD << "\n";
    }

    return 0;
}
