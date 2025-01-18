#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct position_1987 {
    int x, y;
};
bool alphabet_1987[26];
int R_1987, C_1987, MAX_1987 = 0;
vector<vector<char>> graph_1987;
vector<vector<bool>> selected_1987;
position_1987 go_1987[4] = {{1,0}, {0,1}, {-1, 0}, {0, -1}};

void BFS_1987(position_1987 a, int count) {
    MAX_1987 = max(MAX_1987, count);

    for(int i = 0; i < 4; i++) {
        int tempY = go_1987[i].y + a.y;
        int tempX = go_1987[i].x + a.x;

        if(tempX < 0 || tempY < 0 || tempX >= C_1987 || tempY >= R_1987) continue;
        if(selected_1987[tempY][tempX] || alphabet_1987[graph_1987[tempY][tempX] - 'A']) continue;

        selected_1987[tempY][tempX] = true;
        alphabet_1987[graph_1987[tempY][tempX] - 'A'] = true;
        BFS_1987({tempX, tempY}, count + 1);
        selected_1987[tempY][tempX] = false;
        alphabet_1987[graph_1987[tempY][tempX] - 'A'] = false;
    }
}

int main_1987() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R_1987 >> C_1987;

    graph_1987.resize(R_1987, vector<char> (C_1987));
    selected_1987.resize(R_1987, vector<bool> (C_1987));

    for(int y = 0; y < R_1987; y++) {
        for(int x = 0; x < C_1987; x++) {
            cin >> graph_1987[y][x];
        }
    }

    selected_1987[0][0] = true;
    alphabet_1987[graph_1987[0][0] - 'A'] = true;

    BFS_1987({0,0}, 1);

    cout << MAX_1987 << endl;
    return 0;
}