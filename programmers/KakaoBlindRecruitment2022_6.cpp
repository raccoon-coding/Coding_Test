#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> diff(n + 1, vector<int>(m + 1, 0));
    
    for(int i = 0; i < skill.size(); i++) {
        int type = skill[i][0];
        int r1 = skill[i][1];
        int c1 = skill[i][2];
        int r2 = skill[i][3];
        int c2 = skill[i][4];
        int degree = skill[i][5];
        if(type == 1) degree = -1 * degree;
        diff[r1][c1] += degree;
        diff[r1][c2 + 1] -= degree;
        diff[r2 + 1][c1] -= degree;
        diff[r2 + 1][c2 + 1] += degree;
    }
    
    for(int i = 0; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            diff[i][j] += diff[i][j - 1];
        }
    }
    
    for (int j = 0; j < m + 1; j++) {
        for (int i = 1; i < n + 1; i++) {
            diff[i][j] += diff[i - 1][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            board[i][j] += diff[i][j];
            if (board[i][j] > 0) answer++;
        }
    }
    return answer;
}