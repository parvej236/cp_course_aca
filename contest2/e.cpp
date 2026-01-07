#include <bits/stdc++.h>
using namespace std;

static const int MAXN = 30005;

vector<pair<int,int>> adj[MAXN];
bool visited[MAXN];
long long distArr[MAXN];

pair<int, long long> dfs(int start, int n) {
    stack<int> st;
    st.push(start);

    for (int i = 0; i < n; i++) {
        visited[i] = false;
        distArr[i] = 0;
    }

    visited[start] = true;

    while (!st.empty()) {
        int u = st.top();
        st.pop();

        for (auto &p : adj[u]) {
            int v = p.first;
            int w = p.second;

            if (!visited[v]) {
                visited[v] = true;
                distArr[v] = distArr[u] + w;
                st.push(v);
            }
        }
    }

    long long maxDist = -1;
    int node = -1;
    for (int i = 0; i < n; i++) {
        if (distArr[i] > maxDist) {
            maxDist = distArr[i];
            node = i;
        }
    }

    return {node, maxDist};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
            adj[i].clear();

        for (int i = 0; i < n - 1; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // 1st DFS: from node 0 to find farthest node A
        pair<int, long long> p1 = dfs(0, n);

        // 2nd DFS: from node A to find diameter
        pair<int, long long> p2 = dfs(p1.first, n);

        cout << "Case " << t << ": " << p2.second << "\n";
    }

    return 0;
}
