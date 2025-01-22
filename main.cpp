#include <iostream>
#include <vector>

using namespace std;

struct point{
    int x, y;
};

vector<vector<int>> sudoku(9, vector<int>(9));
vector<point> blank;

bool isValid(int row, int col, int num) {
    for (int i = 0; i < 9; i++) {
        if (sudoku[i][row] == num) return false;
    }

    for (int i = 0; i < 9; i++) {
        if (sudoku[col][i] == num) return false;
    }

    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (sudoku[startCol + i][startRow + j] == num) return false;
        }
    }

    return true;
}

bool solveSudoku(int index) {
    if (index == blank.size()) {
        return true;
    }

    int row = blank[index].x;
    int col = blank[index].y;

    for (int num = 1; num <= 9; num++) {
        if (isValid(row, col, num)) {
            sudoku[col][row] = num;
            if (solveSudoku(index + 1)) {
                return true;
            }
            sudoku[col][row] = 0; // 되돌리기
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int y = 0; y < 9; y++) {
        for(int x = 0; x < 9; x++) {
            int temp;
            cin >> temp;
            sudoku[y][x] = temp;
            if(temp == 0) 
                blank.push_back({x, y});
        }
    }

    solveSudoku(0);
    cout << '\n';


    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << sudoku[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
