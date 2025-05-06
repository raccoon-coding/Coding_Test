#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

pair<bool, int> dfs(vector<vector<int>> board, int ax, int ay, int bx, int by, bool turn) {
    int x, y;
    if(turn) {
        x = ax; y = ay;
    } else {
        x = bx; y = by;
    }

    if (board[x][y] == 0) {
        return {false, 0};
    };

    bool canWin = false;
    int minTurn = INT32_MAX, maxTurn = 0;

    board[x][y] = 0;

    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || ny < 0 || nx >= board.size() || ny >= board[0].size()) {
            continue;
        } if (board[nx][ny] == 0) {
            continue;
        }

        if (turn) {
            pair<bool, int> temp = dfs(board, nx, ny, bx, by, !turn);
            bool win = temp.first;
            int cnt = temp.second;
            if (!win) {
                canWin = true;
                minTurn = min(minTurn, cnt + 1);
            } else {
                maxTurn = max(maxTurn, cnt + 1);
            }
        } else {
            pair<bool, int> temp = dfs(board, ax, ay, nx, ny, !turn);
            bool win = temp.first;
            int cnt = temp.second;
            if (!win) {
                canWin = true;
                minTurn = min(minTurn, cnt + 1);
            } else {
                maxTurn = max(maxTurn, cnt + 1);
            }
        }
    }

    board[x][y] = 1;

    if (canWin) {
        return {canWin, minTurn};
    } else {
        return {canWin, maxTurn};
    }
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    auto [win, cnt] = dfs(board, aloc[0], aloc[1], bloc[0], bloc[1], true);
    return cnt;
}