#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<vector<int>> A_1260;
vector<bool> visited_1260;
void DFS_1260(int node);
void BFS_1260(int node);

void BFS_1260(int V){
    queue<int> myqueue;
    myqueue.push(V);
    visited_1260[V] = true;
    // queue 자료구조에 data가 없을 때까지 쭉 진행
    while (!myqueue.empty()) {
        int now_node = myqueue.front();
        myqueue.pop();
        cout << now_node << " ";
        // vector의 크기만큼 반목문을 돌고있음
        for (int i : A_1260[now_node]) {
            if (!visited_1260[i]) {
                visited_1260[i] = true;
                myqueue.push(i);
            }
        }
    }
}

void DFS_1260(int V) {
    cout << V << " ";
    visited_1260[V] = true;
    // 재귀로 가로부터 search 진행
    for(int i : A_1260[V]){
        if(!visited_1260[i]){
            DFS_1260(i);
        }
    }
}


int main_search_1260(){
    int N = 0, M = 0, V = 0;
    cin >> N >> M >> V;
    A_1260.resize(N + 1);
    for(int i = 0; i < M; i++) {
        int N1 = 0, N2 = 0;
        cin >> N1 >> N2;
        A_1260[N1].push_back(N2);
        A_1260[N2].push_back(N1);
    }
    for(int i = 1; i < N + 1; i++)
        sort(A_1260[i].begin(), A_1260[i].end());
    visited_1260 = vector<bool>(N+1, false);
    DFS_1260(V);
    cout << "\n";
    fill(visited_1260.begin(), visited_1260.end(), false);
    BFS_1260(V);
    cout << "\n";
    return 0;
}