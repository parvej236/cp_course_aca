#include <bits/stdc++.h>
using namespace std;

static const int MAXN = 20005;

vector<int> adjList[MAXN];
int color[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int n;
        cin >> n;

        // Reset graph
        for (int i = 0; i < MAXN; i++) {
            adjList[i].clear();
            color[i] = -1;
        }

        set<int> nodes;

        // Read fights
        for (int i = 0; i < n; i++) {
            int u, v;
            cin >> u >> v;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
            nodes.insert(u);
            nodes.insert(v);
        }

        long long result = 0;

        for (int node : nodes) {
            if (color[node] == -1) {
                // BFS to color the component
                queue<int> q;
                q.push(node);
                color[node] = 0;

                int cnt0 = 1, cnt1 = 0;

                while (!q.empty()) {
                    int u = q.front();
                    q.pop();

                    for (int v : adjList[u]) {
                        if (color[v] == -1) {
                            color[v] = 1 - color[u];
                            if (color[v] == 0) cnt0++;
                            else cnt1++;
                            q.push(v);
                        }
                    }
                }

                result += max(cnt0, cnt1);
            }
        }

        cout << "Case " << t << ": " << result << "\n";
    }

    return 0;
}
