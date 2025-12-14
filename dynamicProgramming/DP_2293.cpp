#include <iostream>
#include <vector>

using namespace std;

int main_2293() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> coins(n), dp(k + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    dp[0] = 1;

    for (int coin : coins) {
        for (int i = coin; i <= k; i++) {
            dp[i] += dp[i - coin]; 
        }
    }

    cout << dp[k] << endl;

    return 0;
}