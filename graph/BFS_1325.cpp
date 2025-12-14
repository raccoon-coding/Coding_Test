#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/*
 * 회사를 해킹 N개의 컴퓨터 존재
 * 컴퓨터는 서로 신 뢰하는 관계, 신뢰하지 않는 관계 2가지로 구성
 * 이때, 하나의 컴퓨터를 해킹했을 때, 신뢰하는 컴퓨터는 모두 해킹 가능
 * 한번에 많은 컴퓨터를 해킹할 수 있는 번호를 출력하라
 * Graph_1325 만든 후 DFS, BFS 수행
 * */
vector<vector<int>> Graph_1325;
vector<int> Result_1325;
vector<bool> visited_1325;
void BFS_1325(int start);

void BFS_1325(int start) {
    queue<int> queue;
    queue.push(start);
    visited_1325[start] = true;
    while (!queue.empty()) {
        int now_node = queue.front();
        queue.pop();
        for (int i : Graph_1325[now_node]) {
            if (!visited_1325[i]) {
                visited_1325[i] = true;
                Result_1325[i]++;
                queue.push(i);
            }
        }
    }
}

int main_1325(){
    long N = 0, M = 0;
    cin >> N >> M;
    Graph_1325.resize(N + 1);
    Result_1325.resize(N + 1);
    visited_1325.resize(N + 1);
    for(int i = 0; i <  M ; i++){
        int comA = 0, comB = 0;
        cin >> comA >> comB;
        Graph_1325[comA].push_back(comB);
    }
    for (int i = 0; i <= N; i++) {
        fill(visited_1325.begin(), visited_1325.end(), false);
        BFS_1325(i);
    }
    int Max = 0;
    for (int i = 1; i <= N; i++) {
        Max = max(Max, Result_1325[i]);
    }
    for (int i = 1; i <= N; i++) {
        if (Result_1325[i] == Max)
            cout << i << " ";
    }
    return 0;
}