#include <iostream>
#include <cmath>
#include <tuple>
#include <vector>
#include <queue>
/**
 * Backjoon 1854 문제는 다익스트라 문제에서 변형된 것이다.
 * 여기서 핵심은 k번째 최소 거리를 구하기 위한 것인데, 거리가 음수가 존재하지 않으므로 다익스트라 알고리즘을 기반으로 사용한다.
 * 이때, 여러 노드를 방문할 수 있으므로, visited 벡터를 사용해서는 안된다.
 * 대신 우선순위 큐 배열을 만들어, 이 배열이 k개가 쌓이면 최소 k개수의 방문이 가능한 것이고, 우선순위 큐의 top만 변경한다.
 * */

using namespace std;
typedef pair<int, int> edge_1854;
vector<vector<edge_1854>> City_1854;
static priority_queue<int> dijkstraQueue_1854[1001]; // 내림차순 8, 5, 1
void dijkstra_1854(int k);

void dijkstra_1854(int k) {
    priority_queue<edge_1854, vector<edge_1854>, greater<edge_1854>> myqueue; // 오름차순 ex> 1, 5, 8
    int distance = 0;
    dijkstraQueue_1854[1].push(0);
    myqueue.push(make_pair(0, 1));
    while(!myqueue.empty()){
        int now = myqueue.top().second;
        distance = myqueue.top().first;
        myqueue.pop();
        for (int i = 0; i < City_1854[now].size(); i++) {
            int next = City_1854[now][i].first;
            int next_distance = City_1854[now][i].second;
            if (dijkstraQueue_1854[next].size() < k) {
                dijkstraQueue_1854[next].push(distance + next_distance);
                myqueue.push(make_pair(distance + next_distance, next));
            }
            else if (dijkstraQueue_1854[next].top() > distance + next_distance) {
                dijkstraQueue_1854[next].pop();
                dijkstraQueue_1854[next].push(distance + next_distance);
                myqueue.push(make_pair(distance + next_distance, next));
            }
        }
    }
}

int main_1854(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n = 0, m = 0, k = 0;
    cin >> n >> m >> k;
    City_1854.resize(n + 1);
    for(int i = 0; i < m; i++){
        int a = 0, b = 0, c = 0;
        cin >> a >> b >> c;
        City_1854[a].emplace_back(b, c);
    }
    dijkstra_1854(k);
    for(int i = 1; i <= n; i++){
        if(dijkstraQueue_1854[i].size() == k)
            cout << dijkstraQueue_1854[i].top() << "\n";
        else
            cout << "-1\n";
    }
    return 0;
}