#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct moving_17070 {
    int dir;
    int x, y;
};

int main_17070() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for(int y = 1; y <= n; y++) {
        for(int x = 1; x <= n; x++) {
            cin >> graph[x][y];
        }
    }

    queue<moving> q;
    q.push({0, 2, 1});
    dp[2][1] = 1;

    //  0 - 가로, 1 - 세로, 2 - 대각선
    while(!q.empty()) {
        int dir = q.front().dir;
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        if(dir == 0) {
            if(x + 1 <= n) {
                if(graph[x + 1][y] == 0) {
                    q.push({0, x + 1 , y});
                    dp[x + 1][y]++;
                }
            }
            if(x + 1 <= n && y + 1 <= n) {
                if(graph[x + 1][y + 1] == 0 && graph[x + 1][y] == 0 && graph[x][y + 1] == 0) {
                    q.push({2, x + 1 , y + 1});
                    dp[x + 1][y + 1]++;
                }
            }
        } else if(dir == 1) {
            if(y + 1 <= n) {
                if(graph[x][y + 1] == 0) {
                    q.push({1, x , y + 1});
                    dp[x][y + 1]++;
                }
            }
            if(x + 1 <= n && y + 1 <= n) {
                if(graph[x + 1][y + 1] == 0 && graph[x + 1][y] == 0 && graph[x][y + 1] == 0) {
                    q.push({2, x + 1 , y + 1});
                    dp[x + 1][y + 1]++;
                }
            }
        } else {
            if(x + 1 <= n) {
                if(graph[x + 1][y] == 0) {
                    q.push({0, x + 1 , y});
                    dp[x + 1][y]++;
                }
            }
            if(y + 1 <= n) {
                if(graph[x][y + 1] == 0) {
                    q.push({1, x , y + 1});
                    dp[x][y + 1]++;
                }
            }
            if(x + 1 <= n && y + 1 <= n) {
                if(graph[x + 1][y + 1] == 0 && graph[x + 1][y] == 0 && graph[x][y + 1] == 0) {
                    q.push({2, x + 1 , y + 1});
                    dp[x + 1][y + 1]++;
                }
            }
        }
    }

    cout << dp[n][n] << endl;

    return 0;
}