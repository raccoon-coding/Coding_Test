#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int board[51][51];
int roomId[51][51];
vector<int> roomSize;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int wallBit[4] = {1, 2, 4, 8};

int bfs_2234(int sx, int sy, int id) {
    queue<pair<int, int>> q;
    q.push({sx, sy});
    roomId[sx][sy] = id;
    int cnt = 1;

    while (!q.empty()) {
        pair<int, int> temp = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            // 해당 방향에 벽이 있으면 이동 불가
            if (board[temp.first][temp.second] & wallBit[dir]) continue;

            int nx = temp.first + dx[dir];
            int ny = temp.second + dy[dir];

            if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
            if (roomId[nx][ny] != -1) continue;

            roomId[nx][ny] = id;
            q.push({nx, ny});
            cnt++;
        }
    }

    return cnt;
}


int main_2234()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            roomId[i][j] = -1;
        }
    }

    int roomCount = 0;
    int maxRoom = 0;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (roomId[i][j] == -1) {
                int size = bfs_2234(i, j, roomCount);
                roomSize.push_back(size);
                maxRoom = max(maxRoom, size);
                roomCount++;
            }
        }
    }

    // 2. 벽 하나 제거해서 만들 수 있는 최대 방 크기
    int maxAfterRemove = 0;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            for (int dir = 0; dir < 4; dir++) {
                // 벽이 있는 방향만 확인
                if (!(board[i][j] & wallBit[dir])) continue;

                int nx = i + dx[dir];
                int ny = j + dy[dir];

                if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;

                int a = roomId[i][j];
                int b = roomId[nx][ny];

                if (a != b) {
                    maxAfterRemove = max(maxAfterRemove, roomSize[a] + roomSize[b]);
                }
            }
        }
    }

    cout << roomCount << endl;
    cout << maxRoom << endl;
    cout << maxAfterRemove << endl;

    return 0;
}
