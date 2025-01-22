#include <iostream>
#include <vector>

using namespace std;

struct point_2580{
    int x, y;
};

vector<vector<int>> sudoku_2580(9, vector<int>(9));
vector<point_2580> blank_2580;

bool isValid_2580(int x, int y, int num) {
    for (int i = 0; i < 9; i++) {
        if (sudoku_2580[i][x] == num) return false;
    }

    for (int i = 0; i < 9; i++) {
        if (sudoku_2580[y][i] == num) return false;
    }

    int startX = (x / 3) * 3;
    int startY = (y / 3) * 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (sudoku_2580[startY + i][startX + j] == num) return false;
        }
    }

    return true;
}

bool solveSudoku_2580(int index) {
    if (index == blank_2580.size()) {
        return true;
    }

    int nx = blank_2580[index].x;
    int ny = blank_2580[index].y;

    for (int num = 1; num <= 9; num++) {
        if (isValid_2580(nx, ny, num)) {
            sudoku_2580[ny][nx] = num;
            if (solveSudoku_2580(index + 1)) {
                return true;
            }
            sudoku_2580[ny][nx] = 0; // 되돌리기
        }
    }

    return false;
}

int main_2580() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int y = 0; y < 9; y++) {
        for(int x = 0; x < 9; x++) {
            int temp;
            cin >> temp;
            sudoku_2580[y][x] = temp;
            if(temp == 0) 
                blank_2580.push_back({x, y});
        }
    }

    solveSudoku_2580(0);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << sudoku_2580[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
