#include <iostream>
#include <vector>

using namespace std;

struct grape_2156{
    int count, max;
};

int main_2156() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    int alcol[N];
    grape_2156 dp[N];
    for(int i = 0; i < N; i++) {
        cin >> alcol[i];
    }

    dp[0] = {1, alcol[0]};
    dp[1] = {2, alcol[1] + dp[0].max};
    if(alcol[2] + dp[0].max > dp[1].max) {
        if(alcol[2] + dp[0].max > alcol[1] + alcol[2]) {
            dp[2] = {1, alcol[2] + dp[0].max};
        } else {
            dp[2] = {2, alcol[1] + alcol[2]};
        }
    } else {
        if(dp[1].max > alcol[1] + alcol[2]) {
            dp[2] = {0, dp[1].max};
        } else {
            dp[2] = {2, alcol[1] + alcol[2]};
        }
    }

    for(int i = 3; i < N; i++) {
        if(dp[i - 1].count == 2) {
            if(alcol[i] + dp[i - 2].max > dp[i - 1].max) {
                if(alcol[i] + dp[i - 2].max > dp[i - 3].max + alcol[i - 1] + alcol[i]) {
                    dp[i] = {1, alcol[i] + dp[i - 2].max};
                } else {
                    dp[i] = {2, dp[i - 3].max + alcol[i - 1] + alcol[i]};
                }
            } else {
                if(dp[i - 1].max > dp[i - 3].max + alcol[i - 1] + alcol[i]) {
                    dp[i] = {0, dp[i - 1].max};
                } else {
                    dp[i] = {2, dp[i - 3].max + alcol[i - 1] + alcol[i]};
                }
            }
        } else {
            dp[i] = {dp[i - 1].count + 1, dp[i - 1].max + alcol[i]};
        }
    }

    cout << dp[N - 1].max << endl;

    return 0;
}