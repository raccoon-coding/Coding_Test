#include <iostream>
#include <vector>

using namespace std;

int answer_2798 = 0, M_2798, N_2798;
vector<int> cards_2798;

void dfs_2798(int depth, int sum, vector<bool> visited);

void dfs_2798(int depth, int sum, vector<bool> visited) {
    if(depth == 3) {
        if(M_2798 - sum >= 0 && answer_2798 < sum) {
            answer_2798 = sum;
        }
        return;
    }

    for(int i = 0; i < N_2798; i++) {
        if(!visited[i]) {
            visited[i] = true;
            dfs_2798(depth + 1, sum + cards_2798[i], visited);
            visited[i] = false;
        }
    }
}

int main_2798() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N_2798 >> M_2798;
    answer_2798 = 0;
    
    cards_2798.resize(N_2798);
    for(int i = 0; i <  N_2798; i++) {
        cin >> cards_2798[i];
    }

    vector<bool> visited (N_2798, false);
    dfs_2798(0, 0, visited);
    cout << answer_2798 << "\n";

    return 0;
}