#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main_2294() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> coin(n, 0), dp(k + 1, INT16_MAX);
    for(int i = 0; i <  n; i++) {
        cin >> coin[i];
    }

    dp[0] = 0;
    for(int i = 0; i < n; i++) {
        for (int j = coin[i]; j <= k; j++) {
            dp[j] = min(dp[j], dp[j - coin[i]] + 1);
        }
    }

    if(dp[k] == INT16_MAX) {
        dp[k] = -1;
    }

    cout << dp[k] << endl;

    return 0;
}