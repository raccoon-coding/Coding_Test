#include <iostream>
#include <vector>

using namespace std;

int main_2225() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<vector<long long>> dp(n + 1, vector<long long> (k + 1, 1));
    long long num = 1000000000;

    for(int i = 2; i <= k; i++) {
        for(int j = 1; j <= n; j++) {
            long long count = 0;
            for(int k = j; k >= 0; k--) {
                count += dp[k][i - 1];
            }
            dp[j][i] = count % num;
        }
    }

    cout << dp[n][k] << endl;
    return 0;
}