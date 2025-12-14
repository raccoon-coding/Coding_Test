#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main_9251() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string A, B;
    cin >> A >> B;
    
    int N = A.size();
    int M = B.size();
    
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[N][M] << endl;

    return 0;
}