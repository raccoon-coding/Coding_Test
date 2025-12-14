#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct backpack_12865{
    int w, v;
};

int main_12865() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<backpack> bp;
    vector<int> dp(k + 1, 0);
    for(int i = 0; i < n; i++) {
        int w,v;
        cin >> w >> v;
        bp.push_back({w,v});
    }

    for (int i = 0; i < n; i++) {
        int w = bp[i].w, v = bp[i].v;
        for (int j = k; j >= w; j--) {
            dp[j] = max(dp[j], dp[j - w] + v);
        }
    }
    
    cout << dp[k] << endl;
    return 0;
}