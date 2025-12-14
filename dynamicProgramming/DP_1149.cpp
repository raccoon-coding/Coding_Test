#include <iostream>
#include <algorithm>

using namespace std;

int color_1149[1001][3]; 
int dp_1149[1001][3];

int main_1149() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> color_1149[i][j];
        }
    }

    dp_1149[1][0] = color_1149[1][0];
    dp_1149[1][1] = color_1149[1][1];
    dp_1149[1][2] = color_1149[1][2];

    for(int i = 2; i <= n; i++) {
        dp_1149[i][0] = min(dp_1149[i-1][1], dp_1149[i-1][2]) + color_1149[i][0];
        dp_1149[i][1] = min(dp_1149[i-1][0], dp_1149[i-1][2]) + color_1149[i][1];
        dp_1149[i][2] = min(dp_1149[i-1][0], dp_1149[i-1][1]) + color_1149[i][2];
    }

    cout << min({dp_1149[n][0], dp_1149[n][1], dp_1149[n][2]}) << endl;

    return 0;
}