#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

static int dx_2178[] = {0, 1, 0, -1};
static int dy_2178[] = {1, 0, -1, 0};
vector<vector<bool>> visited_2178;
void BFS_2178(vector<vector<int>> &A, int x, int y);
static int N_2178, M_2178;

void BFS_2178(vector<vector<int>> &A, int x, int y){
    queue<pair<int, int>> myqueue;
    myqueue.push(make_pair(x,y));
    while (!myqueue.empty()) {
        int now[2];
        now[0] = myqueue.front().first;
        now[1] = myqueue.front().second;
        myqueue.pop();
        visited_2178[y][x] = true;
        for (int k = 0; k < 4; k++) {
            int x = now[0] + dx_2178[k];
            int y = now[1] + dy_2178[k];
            if (x >= 0 && y >= 0 && y < N_2178 && x < M_2178) {
                if (A[y][x] != 0 && !visited_2178[y][x]) {
                    visited_2178[y][x] = true;
                    A[y][x] = A[now[1]][now[0]] + 1;
                    myqueue.push(make_pair(x, y));
                }
            }
        }
    }
}

int main_2178(){
    cin >> N_2178 >> M_2178;
    vector<vector<int>> A_2178;
    A_2178.resize(N_2178, vector<int>(M_2178));
    visited_2178.resize(N_2178, vector<bool>(M_2178, false));
    for (int i = 0; i < N_2178; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M_2178; j++) {
            A_2178[i][j] = s[j] - '0';
        }
    }
    BFS_2178(A_2178, 0, 0);
    cout << A_2178[N_2178-1][M_2178-1] << "\n";
    return 0;
}