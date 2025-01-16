#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> queenPosition_9663; // 각 행마다 퀸이 위치한 열을 저장하는 배열
int result_9663 = 0;

bool isSafe_9663(int row, int column) {
    // 이전 행들에 대해 퀸이 현재 위치(row, column)에 놓일 수 있는지 확인
    for (int i = 0; i < row; i++) {
        // 같은 열에 있거나, 대각선에 위치하면 false, 이 때, 같은 행에 있는것은 조사하지 않으므로 덮어씌워지게 된다.
        if (queenPosition_9663[i] == column || abs(queenPosition_9663[i] - column) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

void backtracking_9663(int row, int graphSize) {
    if (row == graphSize) {
        // 모든 행에 퀸을 배치했을 때 경우의 수 증가
        result_9663++;
        return;
    }

    // 현재 행에서 각 열에 퀸을 놓아보며 가능한지 확인
    for (int col = 0; col < graphSize; col++) {
        if (isSafe_9663(row, col)) {
            queenPosition_9663[row] = col; // 퀸을 현재 위치에 놓음
            backtracking_9663(row + 1, graphSize); // 다음 행으로 넘어감
            // 돌아오면 퀸을 다른 위치에 놓아야 하므로 현재 퀸의 위치는 따로 해제하지 않음
        }
    }
}

int main_9663() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int size;
    cin >> size;

    queenPosition_9663.resize(size); // 각 행에 퀸이 위치할 열을 저장하는 배열 크기 설정

    backtracking_9663(0, size); // 첫 번째 행부터 시작

    cout << result_9663 << '\n'; // 결과 출력

    return 0;
}
