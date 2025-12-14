#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main_1005() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    vector<int> result;
    
    for(int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;

        vector<int> D(n + 1, 0);
        vector<vector<int>> build(n + 1);
        vector<int> inDegree(n + 1, 0);
        vector<int> dp(n + 1, 0);

        for (int j = 1; j <= n; j++) {
            cin >> D[j];
        }

        for (int j = 0; j < k; j++) {
            int a, b;
            cin >> a >> b;
            build[a].push_back(b);
            inDegree[b]++;
        }

        int end;
        cin >> end;

        queue<int> q;
        for (int j = 1; j <= n; j++) {
            if (inDegree[j] == 0) {
                q.push(j);
                dp[j] = D[j];
            }
        }

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (int next : build[cur]) {
                dp[next] = max(dp[next], dp[cur] + D[next]);
                if (--inDegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        result.push_back(dp[end]);
    }

    for(int time : result) {
        cout << time << endl;
    }
    return 0;
}