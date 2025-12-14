#include <iostream>
#include <vector>

using namespace std;

int main_2133() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    if(n % 2 != 0) {
        return 0;
    }

    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[2] = 3;

    for(int i = 4; i <= n; i += 2) {
        dp[i] = dp[i - 2] * 3;
        for(int j = i - 4; j >= 0; j -= 2) {
            dp[i] += dp[j] * 2;
        }
    }

    cout << dp[n] << endl;

    return 0;
}