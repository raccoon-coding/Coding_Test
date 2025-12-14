#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main_14002() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> list(n, 0);
    vector<int> dp(n, 1);
    vector<vector<int>> dplist(n);
    for(int i = 0; i < n; i++) {
        cin >> list[i];
        dplist[i].push_back(list[i]);
    }

    int index = 0, MaxCount = 1;
    for(int i = 1; i < n; i++) {
        int maxDp = 0;
        int vectorIndex = -1;
        
        for (int j = 0; j < i; j++) {
            if (list[j] < list[i] && dp[j] > maxDp) {
                maxDp = dp[j];
                vectorIndex = j;
            }
        }

        if (vectorIndex != -1) {
            dp[i] = dp[vectorIndex] + 1;
            dplist[i] = dplist[vectorIndex];
            dplist[i].push_back(list[i]);
        }

        if (dp[i] > MaxCount) {
            MaxCount = dp[i];
            index = i;
        }
    }

    cout << MaxCount << endl;
    for(int i = 0; i < dplist[index].size(); i++) {
        cout << dplist[index][i] << " ";
    }
    cout << endl;

    return 0;
}