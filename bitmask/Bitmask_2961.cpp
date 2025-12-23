#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<pair<long, long>> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second; // S, B
    }

    long answer = LONG_MAX;

    for (int mask = 1; mask < (1 << N); mask++) {
        long sour = 1;
        long bitter = 0;

        for (int i = 0; i < N; i++) {
            if (mask & (1 << i)) {
                sour *= v[i].first;
                bitter += v[i].second;
            }
        }

        answer = min(answer, labs(sour - bitter));
    }

    cout << answer << "\n";
    return 0;
}