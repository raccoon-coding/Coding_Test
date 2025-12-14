#include <iostream>
#include <vector>
#include <queue>

using namespace std;
struct edge_1520 {
    int level, x, y;
    bool operator<(const edge_1520& other) const {
        return level < other.level;
    }
};

int dx_1520[4] = {0, 0, 1, -1};
int dy_1520[4] = {1, -1, 0, 0};

int main_1520() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n, vector<int> (m, 0));
    vector<vector<int>> dp(n, vector<int> (m, 0));
    vector<vector<bool>> visited(n, vector<bool> (m, false));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }

    priority_queue<edge_1520> q;
    q.push({graph[0][0], 0, 0});
    dp[0][0] = 1;
    while(!q.empty()) {
        int x = q.top().x;
        int y = q.top().y;
        int h = q.top().level;
        q.pop();
        visited[x][y] = true;
        int path = dp[x][y];
        if(x  == n - 1 && y == m - 1) {
            continue;
        }
        for(int i = 0; i < 4; i++) {
            int nx = dx_1520[i] + x;
            int ny = dy_1520[i] + y;
            if(nx >= 0 && ny >= 0 && nx < n && ny < m && graph[nx][ny] < h) {
                if (dp[nx][ny] == 0) {
                    q.push({graph[nx][ny], nx, ny});
                }
                dp[nx][ny] += dp[x][y];
            }
        }
    }
    cout << dp[n - 1][m - 1] << endl;
    return 0;
}