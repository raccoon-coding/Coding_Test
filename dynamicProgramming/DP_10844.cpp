#include <iostream>
#include <vector>

using namespace std;

int main_10844() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    long long number = 1000000000;

    vector<vector<long long>> dp(100, vector<long long> (10, 0));
    for(int i = 1; i < 10; i++) {
        dp[0][i] = 1;
    }

    for(int i = 1; i < N; i++) {
        for(int j = 0; j < 10; j++) {
            if(j == 0) {
                dp[i][j] = dp[i - 1][1] % number;
            } else if(j == 9) {
                dp[i][j] = dp[i - 1][8] % number;
            } else {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % number;
            }
        }
    }

    long long result = 0;
    for(int i = 0; i < 10; i++) {
        result = (result + dp[N - 1][i]) % number;
    }
    
    cout << result << endl;

    return 0;
}