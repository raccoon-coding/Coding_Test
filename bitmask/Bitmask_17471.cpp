#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int N;
vector<int> v;
vector<vector<int>> s;

bool isConnected_17471(int mask) {
    int start = -1;
    for (int i = 1; i <= N; i++) {
        if (mask & (1 << i)) {
            start = i;
            break;
        }
    }
    if (start == -1) return false;

    vector<int> visited(N + 1, 0);
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    int cnt = 1;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int nxt : s[cur]) {
            if (!(mask & (1 << nxt))) continue;
            if (visited[nxt]) continue;
            visited[nxt] = 1;
            q.push(nxt);
            cnt++;
        }
    }

    int total = 0;
    for (int i = 1; i <= N; i++) {
        if (mask & (1 << i)) total++;
    }

    if (cnt == total) return true;
    return false;
}

int main_17471() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    v.assign(N + 1, 0);
    for (int i = 1; i <= N; i++) cin >> v[i];

    s.assign(N + 1, {});
    for (int i = 1; i <= N; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            s[i].push_back(x); // 입력이 1-index
        }
    }

    int full = 0;
    for (int i = 1; i <= N; i++) {
        full |= (1 << i);
    }

    int ans = INT_MAX;

    for (int maskA = 1; maskA < full; maskA++) {
        // 0번 비트 사용 금지(1..N만 사용)
        if (maskA & 1) continue;

        int maskB = full ^ maskA;
        if (maskB == 0) continue;

        if (!isConnected_17471(maskA)) continue;
        if (!isConnected_17471(maskB)) continue;

        int sumA = 0, sumB = 0;
        for (int i = 1; i <= N; i++) {
            if (maskA & (1 << i)) sumA += v[i];
            else sumB += v[i];
        }

        int diff = abs(sumA - sumB);
        if (diff < ans) ans = diff;
    }

    if (ans == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}
