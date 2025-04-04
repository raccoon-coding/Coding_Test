#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    if(n % 2 != 0) {
        return 0;
    }

    vector<int> dp(n + 1, 0);
    dp[2] = 3;
    dp[4] = 11; // dp[2] * 3 + 2
    // dp[6] = dp[4] * 3 + dp[2] * 2;

    for(int i = 3; i <= n/2; i++) {
        dp[i * 2] = dp[(i - 1) * 2] * 3 + dp[(i - 2) * 2] * 2;
    }

    cout << dp[n] << endl;

    return 0;
}