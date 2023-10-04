#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> Graph_1707;
vector<bool> visited_1707;
vector<int> check_1707;
bool IsTrue_1707;
void DFS_1707(int node);

void DFS_1707(int node) {
    visited_1707[node] = true;
    for (int i : Graph_1707[node]) {
        if (!visited_1707[i]) {
            check_1707[i] = (check_1707[node] + 1) % 2;
            DFS_1707(i);
        }
        else if (check_1707[node] == check_1707[i]) {
            IsTrue_1707 = false;
        }
    }
}

int main_1707(){
    int K = 0;
    cin >> K;
    for(int k = 0; k <  K; k++){
        int V = 0, E = 0;
        cin >> V >> E;
        Graph_1707.resize(V + 1);
        check_1707.resize(V + 1);
        visited_1707.resize(V + 1);
        IsTrue_1707 = true;
        for(int i = 0; i < E; i++){
            int N1 = 0, N2 = 0;
            cin >> N1 >> N2;
            Graph_1707[N1].push_back(N2);
            Graph_1707[N2].push_back(N1);
        }
        for (int i = 1; i <= V; i++) {
            if (IsTrue_1707)
                DFS_1707(i);
            else
                break;
        }
        if (IsTrue_1707)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
        for (int i = 0; i <= V; i++) {
            Graph_1707[i].clear();
            visited_1707[i] = false;
            check_1707[i] = 0;
        }
    }
    return 0;
}