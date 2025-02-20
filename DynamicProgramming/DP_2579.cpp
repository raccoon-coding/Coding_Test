#include <iostream>
#include <cmath>

using namespace std;

int dp_2579[301], stair_2579[301];

int main_2579() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> stair_2579[i];
    }

    if (n == 1) {
        cout << stair_2579[1] << endl;
        return 0;
    }

    dp_2579[1] = stair_2579[1];
    dp_2579[2] = stair_2579[1] + stair_2579[2]; 

    for(int i = 3; i <= n; i++) {
        dp_2579[i] = max(dp_2579[i-2] + stair_2579[i], dp_2579[i-3] + stair_2579[i-1] + stair_2579[i]); 
        // 2계단 전에서 한번에 올라거나, 3계단전에서 한번에 올라온 후, 2번 연속으로 올라오기
    }

    cout << dp_2579[n] << endl;
    return 0;
}