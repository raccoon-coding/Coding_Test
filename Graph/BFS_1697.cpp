#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;
int BFS_1697(int index, int focus);

int BFS_1697(int index, int focus) {

    vector<bool> visited(100001, false);
    queue<pair<int, int>> q;
    q.push(make_pair(index, 0));

    while(!q.empty()) {

        int position = q.front().first;
        int count = q.front().second;
        q.pop();

        if (position == focus) {

            return count;
        }

        if (position - 1 >= 0 && !visited[position - 1]) {

            visited[position - 1] = true;
            q.push(make_pair(position - 1, count + 1));
        } if (position + 1 <= 100000 && !visited[position + 1]) {

            visited[position + 1] = true;
            q.push(make_pair(position + 1, count + 1));
        } if (position * 2 <= 100000 && !visited[position * 2]) {

            visited[position * 2] = true;
            q.push(make_pair(position * 2, count + 1));
        }
    }
    return -1;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;

    cin >> N >> K;

    vector<vector<int>> graph;

    cout << BFS_1697(N, K) << '\n';

    return 0;
}