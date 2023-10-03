#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> A_11724;
vector<bool> visited_11724;
void DFS_11724(int start);

void DFS_11724(int start){
    if(visited_11724[start])
        return;
    visited_11724[start] = true;
    for (int i : A_11724[start]) {
        if (!visited_11724[i]) {
            DFS_11724(i);
        }
    }
}

int main_11724(){
    int N = 0, M = 0, u = 0, v = 0, count = 0;

    cin >> N >> M;
    visited_11724.resize(N + 1, false);
    A_11724.resize(N + 1);

    for(int i = 1; i <= M; i++){
        cin >> u >> v;
        A_11724[u].push_back(v);
        A_11724[v].push_back(u);
    }

    for(int i = 1; i <= N; i++){
        if(!visited_11724[i]) {
            count++;
            DFS_11724(i);
        }
    }
    cout << count << "\n";
    return 0;
}