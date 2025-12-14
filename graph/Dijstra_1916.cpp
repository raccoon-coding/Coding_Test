#include <iostream>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> edge_1916;
vector<vector<edge_1916>> Graph_1916;
vector<bool> visited_1916;
vector<int> result_1916;
void Dijstra_1916(int start, int end);

void Dijstra_1916(int start, int end) {
    priority_queue<edge_1916, vector<edge_1916>, greater<edge_1916>> myqueue;
    myqueue.emplace(0, start);
    result_1916[start] = 0;
    while(!myqueue.empty()){
        int now = myqueue.top().second;
        myqueue.pop();
        if(now == end)
            continue;
        if (!visited_1916[now]) {
            visited_1916[now] = true;
            for (int i = 0; i < Graph_1916[now].size(); i++) {
                int next_node = Graph_1916[now][i].first;
                int weight = Graph_1916[now][i].second;
                if (result_1916[next_node] > weight + result_1916[now]) {
                    result_1916[next_node] = weight + result_1916[now];
                    myqueue.emplace(result_1916[next_node], next_node);
                }
            }
        }
    }
}

int main_1916(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N = 0, M = 0, startNode = 0, endNode = 0;
    cin >> N >> M;
    Graph_1916.resize(N + 1);
    result_1916.resize(N + 1, INT32_MAX);
    visited_1916.resize(N + 1, false);
    for(int i = 0; i < M; i++){
        int start, end, cost;
        cin >> start >> end >> cost;
        Graph_1916[start].emplace_back(end, cost);
    }
    cin >> startNode >> endNode;
    Dijstra_1916(startNode, endNode);
    cout << result_1916[endNode];
    return 0;
}