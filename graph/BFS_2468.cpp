#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

int N;

vector<vector<int>> city_2468;
vector<vector<bool>> visited_2468;

int counting_2468(int check);
void BFS_2468(int x, int y, int check);

int counting_2468(int check) {

    int area = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(!visited_2468[i][j] && city_2468[i][j] > check) {
                BFS_2468(j, i, check);
                area++;
            }
        }
    }
    return area;
}

void BFS_2468(int x, int y, int check) {
    // 방향 이동 (상, 하, 좌, 우)
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visited_2468[y][x] = true;  // 시작점을 방문 처리

    while(!q.empty()) {

        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        // 상하좌우 네 방향 탐색
        for(int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            // 범위를 벗어나지 않고, 방문하지 않았으며, 물에 잠기지 않은 영역일 때
            if(nx >= 0 && nx < N && ny >= 0 && ny < N) {
                if(!visited_2468[ny][nx] && city_2468[ny][nx] > check) {
                    visited_2468[ny][nx] = true;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int maxFlood = 0, minFlood = INT16_MAX, result = 1;

    cin >> N;

    city_2468.resize(N, vector<int> (N, 0));
    visited_2468.resize(N, vector<bool> (N, false));

    for(int i = 0; i <  N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> city_2468[j][i];
            maxFlood = max(maxFlood, city_2468[j][i]);
            minFlood = min(minFlood, city_2468[j][i]);
        }
    }

    for(int i = minFlood; i < maxFlood; i++){
        fill(visited_2468.begin(), visited_2468.end(), vector<bool>(N, false));  // 방문 배열 초기화
        result = max(result, counting_2468(i));
    }

    cout << result << "\n";

    return 0;
}