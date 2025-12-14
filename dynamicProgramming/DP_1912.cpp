#include <iostream>
#include <cmath>

using namespace std;

int main_1912() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    int num[N];
    long dp[N];
    for(int i = 0; i < N; i++) {
        cin >> num[i];
    }

    dp[0] = num[0];
    long Max = dp[0];
    for(int i = 1; i < N; i++) {
        if(dp[i - 1] + num[i] < num[i]) {
            dp[i] = num[i];
        } else {
            dp[i] = dp[i - 1] + num[i];
        }
        Max = max(dp[i], Max);
    }

    cout << Max << endl;

    return 0;
}