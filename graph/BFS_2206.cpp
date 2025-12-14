#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int N_2206, M_2206;
vector<vector<int>> graph_2206;
vector<vector<vector<int>>> visited_2206;

int dx_2206[] = {0, 0, 1, -1};
int dy_2206[] = {1, -1, 0, 0};

void BFS_2206() {

    queue<tuple<int, int, int>> q;  // (x, y, 벽을 부순 상태(0 또는 1))
    q.push({0, 0, 1});
    visited_2206[0][0][1] = 1; // 시작점 방문 처리 (벽을 부수지 않음)

    while (!q.empty()) {
        
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int broken = get<2>(q.front());  // 벽을 부쉈는지 여부 (1: 부수지 않음, 0: 부숨)
        q.pop();

        // 도착점에 도달한 경우
        if (x == M_2206 - 1 && y == N_2206 - 1) {

            cout << visited_2206[y][x][broken] << "\n";
            return;
        }

        for (int i = 0; i < 4; i++) {

            int nx = x + dx_2206[i];
            int ny = y + dy_2206[i];
            
            if (nx >= 0 && ny >= 0 && nx < M_2206 && ny < N_2206) {
                
                // 벽이 없는 경우
                if (graph_2206[ny][nx] == 0 && visited_2206[ny][nx][broken] == 0) {

                    visited_2206[ny][nx][broken] = visited_2206[y][x][broken] + 1;
                    q.push({nx, ny, broken});
                }

                // 벽이 있는 경우, 벽을 한 번도 부수지 않았을 때만 벽을 부수고 이동 가능
                else if (graph_2206[ny][nx] == 1 && broken == 1 && visited_2206[ny][nx][1] == 0) {

                    visited_2206[ny][nx][0] = visited_2206[y][x][broken] + 1;
                    q.push({nx, ny, 0});  // 벽을 부순 상태로 큐에 추가
                }
            }
        }
    }

    // 도착하지 못했을 때
    cout << -1 << "\n";
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N_2206 >> M_2206;

    graph_2206.resize(N_2206, vector<int>(M_2206));
    visited_2206.resize(N_2206, vector<vector<int>>(M_2206, vector<int>(2, 0)));  // 2차원 배열에 벽을 부순 여부 추가

    for (int i = 0; i < N_2206; i++) {

        string row;
        cin >> row;
        for (int j = 0; j < M_2206; j++) {

            graph_2206[i][j] = row[j] - '0';
        }
    }

    BFS_2206();

    return 0;
}