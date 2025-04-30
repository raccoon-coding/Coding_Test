#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string as, bs;
    cin >> as >> bs;

    int n = as.size(), m = bs.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (as[i - 1] == bs[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    string lcs;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (as[i - 1] == bs[j - 1]) {
            lcs += as[i - 1];
            i--; j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    reverse(lcs.begin(), lcs.end());

    cout << dp[n][m] << endl;
    if (!lcs.empty()) cout << lcs << endl;

    return 0;
}