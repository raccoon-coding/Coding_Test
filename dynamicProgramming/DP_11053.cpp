#include <iostream>
#include <vector>

using namespace std;

int main_11053() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    int nums[N],  maxLength = 1;
    vector<int> dp(N, 1);

    for(int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    for(int i = 1; i < N; i++) {
        for(int j = 0; j < i; j++) {
            if(nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxLength = max(maxLength, dp[i]);
    }

    cout << maxLength << endl;

    return 0;
}