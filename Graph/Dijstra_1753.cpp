#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

/**
 * Dijkstra Algorithm by priority queue
 * */
using namespace std;

typedef pair<int, int> edge_1753;
vector<vector<edge_1753>> DirectGraph_1753;
vector<int> result_1753;
vector<bool> visitedNode_1753;
void dijkstra_1753(int startNode);

void dijkstra_1753(int startNode){
    priority_queue<edge_1753, vector<edge_1753>, greater<edge_1753>> myqueue;
    int sumWeight = 0;
    myqueue.push(make_pair(sumWeight, startNode));
    result_1753[startNode] = 0;
    while(!myqueue.empty()){
        int now = myqueue.top().second;
        myqueue.pop();
        if(visitedNode_1753[now])
            continue;
        visitedNode_1753[now] = true;
        for(int i = 0; i < DirectGraph_1753[now].size(); i++){
            int next_node = DirectGraph_1753[now][i].first;
            int weight = DirectGraph_1753[now][i].second;
            if(result_1753[next_node] > weight + result_1753[now]) {
                result_1753[next_node] = weight + result_1753[now];
                myqueue.push(make_pair(result_1753[next_node], next_node));
            }
        }
    }
}

int main_1753(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int V = 0, E = 0, startNode = 0;
    cin >> V >> E >> startNode;

    DirectGraph_1753.resize(V + 1);
    visitedNode_1753.resize(V + 1, false);
    result_1753.resize(V + 1, INT32_MAX);

    for(int i = 0; i < E; i++){
        int u = 0, v = 0, w = 0;
        cin >> u >> v >> w;
        DirectGraph_1753[u].emplace_back(v, w);
    }

    dijkstra_1753(startNode);

    for(int i = 1; i <= V; i++){
        if(!visitedNode_1753[i])
            cout << "INF\n";
        else
            cout << result_1753[i] << "\n";
    }

    return 0;
}