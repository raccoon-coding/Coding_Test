#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> edge_1948;
vector<vector<edge_1948>> DirectGraph_1948;
vector<vector<edge_1948>> RDirectGraph_1948;
vector<bool> visited_1948;
vector<int> result_1948;
vector<int> indegree_1948;

void TopologicalSorting_1948(int start);
int BFS_1948(int start);

void TopologicalSorting_1948(int start){
    queue<int> myqueue;
    myqueue.push(start);
    while(!myqueue.empty()){
        int now = myqueue.front();
        myqueue.pop();
        for(int i = 0; i < DirectGraph_1948[now].size(); i++){
            indegree_1948[DirectGraph_1948[now][i].first]--;
            result_1948[DirectGraph_1948[now][i].first] = max(result_1948[DirectGraph_1948[now][i].first],
                                                              result_1948[now] +DirectGraph_1948[now][i].second);
            if (indegree_1948[DirectGraph_1948[now][i].first] == 0) {
                myqueue.push(DirectGraph_1948[now][i].first);
            }
        }
    }
}

int BFS_1948(int start){
    int count = 0;
    queue<int> myqueue;
    myqueue.push(start);
    while(!myqueue.empty()){
        int now = myqueue.front();
        myqueue.pop();
        for(int i = 0; i < RDirectGraph_1948[now].size(); i++){
            if (result_1948[RDirectGraph_1948[now][i].first] + RDirectGraph_1948[now][i].second == result_1948[now]) {
                count++;
                if (!visited_1948[RDirectGraph_1948[now][i].first]) {
                    visited_1948[RDirectGraph_1948[now][i].first] = true;
                    myqueue.push(RDirectGraph_1948[now][i].first);
                }
            }
        }
    }
    return count;
}

int main_1948()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    DirectGraph_1948.resize(N + 1);
    RDirectGraph_1948.resize(N + 1);
    result_1948.resize(N + 1, 0);
    indegree_1948.resize(N + 1, 0);
    visited_1948.resize(N + 1, false);
    for(int i = 0; i < M; i++){
        int start, end, cost;
        cin >> start >> end >> cost;
        DirectGraph_1948[start].push_back(make_pair(end, cost));
        RDirectGraph_1948[end].push_back(make_pair(start, cost));
        indegree_1948[end]++;
    }
    int startNode, endNode;
    cin >> startNode >> endNode;
    TopologicalSorting_1948(startNode);
    int count = BFS_1948(endNode);
    cout << result_1948[endNode] << "\n";
    cout << count << "\n";
    return 0;
}
