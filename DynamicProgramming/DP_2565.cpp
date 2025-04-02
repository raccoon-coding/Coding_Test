#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main_2565() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    vector<pair<int, int>> lines(N);
    
    for (int i = 0; i < N; i++) {
        cin >> lines[i].first >> lines[i].second;
    }

    sort(lines.begin(), lines.end());

    vector<int> dp(N, 1);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (lines[j].second < lines[i].second) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    
    int Max = 0;
    for(int i = 0; i < dp.size(); i++) {
        Max = max(Max, dp[i]);
    }

    cout << N - Max << endl;
    return 0;
}