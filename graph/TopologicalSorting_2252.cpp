#include <iostream>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;
vector<vector<int>> Graph_2252;
vector <int>  indegree_2252;
void TopologicalSorting_2252();

void TopologicalSorting_2252() {
    queue<int> queue;
    for (int i = 1; i < Graph_2252.size(); i++) {
        if (indegree_2252[i] == 0) {
            queue.push(i);
        }
    }
    while (!queue.empty()) {
        int now = queue.front();
        queue.pop();
        cout << now << " ";
        for (int next : Graph_2252[now]) {
            indegree_2252[next]--;
            if (indegree_2252[next] == 0) {
                queue.push(next);
            }
        }
    }
}

int main_2252()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    Graph_2252.resize(N + 1);
    indegree_2252.resize(N + 1, 0);
    for (int i = 0; i < M; i++) {
        int S, E;
        cin >> S >> E;
        Graph_2252[S].push_back(E);
        indegree_2252[E]++;
    }
    TopologicalSorting_2252();
    return 0;
}