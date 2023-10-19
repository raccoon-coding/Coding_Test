#include <iostream>
#include <cmath>
#include <vector>
#include <queue>

/*
 * N개의 도시가 있다.
 * 그리고 한 도시에서 출발하여 다른 도시에 도착하는 M개의 버스가 있다.
 * 우리는 A번째 도시에서 B번째 도시까지 가는데 드는 버스 비용을 최소화 시키려고 한다.
 * A번째 도시에서 B번째 도시까지 가는데 드는 최소비용을 출력하여라.
 * 도시의 번호는 1부터 N까지이다.
 * 첫째 줄에 도시의 개수 N(1 ≤ N ≤ 1,000)이 주어지고 둘째 줄에는 버스의 개수 M(1 ≤ M ≤ 100,000)이 주어진다.
 * 그리고 셋째 줄부터 M+2줄까지 다음과 같은 버스의 정보가 주어진다. 먼저 처음에는 그 버스의 출발 도시의 번호가 주어진다.
 * 그리고 그 다음에는 도착지의 도시 번호가 주어지고 또 그 버스 비용이 주어진다.
 * 버스 비용은 0보다 크거나 같고, 100,000보다 작은 정수이다.
 * 그리고 M+3째 줄에는 우리가 구하고자 하는 구간 출발점의 도시번호와 도착점의 도시번호가 주어진다.
 * 출발점에서 도착점을 갈 수 있는 경우만 입력으로 주어진다.
 */

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