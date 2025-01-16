#include <iostream>
#include <cmath>
#include <vector>

/*
 * 시작 노드는 항상 Yes다. 항상 초기값을 기억하자.
 * */

using namespace std;
vector<vector<int>> Graph_1976;
vector<int> Plan_1976;
vector<bool> visited_1976;
void DFS_1976(int nowCity);

void DFS_1976(int nowCity) {
    for(int i = 0; i < Graph_1976[nowCity].size(); i++){
        if(!visited_1976[Graph_1976[nowCity][i]]) {
            visited_1976[Graph_1976[nowCity][i]] = true;
            DFS_1976(Graph_1976[nowCity][i]);
        }
    }
}

int main_1976()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    Graph_1976.resize(N + 1);
    visited_1976.resize(N + 1, false);
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            int temp;
            cin >> temp;
            if(temp == 1)
                Graph_1976[i].push_back(j);
        }
    }
    for(int i = 0; i < M; i++){
        int temp;
        cin >> temp;
        Plan_1976.push_back(temp);
    }
    visited_1976[Plan_1976[0]] = true;
    DFS_1976(Plan_1976[0]);
    for(int i = 0; i < Plan_1976.size(); i++)
        if(!visited_1976[Plan_1976[i]]) {
            cout << "NO\n";
            return 0;
        }
    cout << "YES\n";
    return 0;
}
