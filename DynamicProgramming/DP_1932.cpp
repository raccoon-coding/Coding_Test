#include <iostream>
#include <vector>

using namespace std;

int main_1932() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<vector<int>> nums(N), dp(N);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < i + 1; j++) {
            int temp;
            cin >> temp;
            nums[i].push_back(temp);
        }
    }

    dp[0].push_back(nums[0][0]);

    for(int i = 1; i < N; i++) {
        for(int j = 0; j < i + 1; j++) {
            if(j == 0) {
                dp[i].push_back(nums[i][j] + dp[i - 1][0]);
            } else if(j == i) {
                dp[i].push_back(nums[i][j] + dp[i - 1][i - 1]);
            } else {
                if(dp[i - 1][j - 1] > dp[i - 1][j]){
                    dp[i].push_back(nums[i][j] + dp[i - 1][j - 1]);
                } else {
                    dp[i].push_back(nums[i][j] + dp[i - 1][j]);
                }
            }
        }
    }
    int Max = 0;
    for(int i = 0; i < N + 1; i++) {
        Max = max(Max, dp[N - 1][i]);
    }

    cout << Max << endl;

    return 0;
}