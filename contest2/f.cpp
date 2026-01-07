#include <bits/stdc++.h>
using namespace std;

int W, H;
char grid[25][25];
bool vis[25][25];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int dfs(int x, int y) {
    vis[y][x] = true;
    int cnt = 1;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < W && ny >= 0 && ny < H) {
            if (!vis[ny][nx] && grid[ny][nx] == '.')
                cnt += dfs(nx, ny);
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {

        cin >> W >> H;

        int sx = -1, sy = -1;

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> grid[i][j];
                if (grid[i][j] == '@') {
                    sx = j;
                    sy = i;
                }
            }
        }

        memset(vis, false, sizeof(vis));

        // starting cell is always '@'
        // treat '@' as land
        grid[sy][sx] = '.';

        int ans = dfs(sx, sy);

        cout << "Case " << tc << ": " << ans << "\n";
    }

    return 0;
}
