#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> A_13023;
vector<bool> visited_13023;
static bool result_13023;
void DFS_13023(int now, int depth);

void DFS_13023(int now, int depth) {
    if (depth == 5 || result_13023) { // 깊이가 5인 경우를 찾은 후 그 후에 접근하는건 서치를 안 돌리기 위해 result가 들어가 있음
        result_13023 = true;
        return;
    }
    visited_13023[now] = true;
    for (int i : A_13023[now]) {
        if (!visited_13023[i]) {
            DFS_13023(i, depth + 1);
        }
    }
    visited_13023[now] = false;
}


int main_13023(){
    int N = 0, M = 0;
    result_13023 = false;
    cin >> N >> M;
    A_13023.resize(N);
    visited_13023.resize(N, false);

    for(int i = 0; i < M; i++){
        int A, B;
        cin >> A >> B;
        A_13023[A].push_back(B);
        A_13023[B].push_back(A);
    }
    for(int i = 0; i < N; i++) {
        DFS_13023(i, 1);
        if(result_13023)
            break;
    }
    if(result_13023)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}