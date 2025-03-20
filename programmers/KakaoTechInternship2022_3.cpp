#include <vector>
#include <queue>
#include <iostream>

using namespace std;

typedef pair<int, int> Node;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<vector<pair<int, int>>> mountainPath(n + 1);
    vector<int> minIntensity(n + 1, INT32_MAX);
    vector<bool> isGate(n + 1, false);
    vector<bool> isSummit(n + 1, false);
    for (auto& path : paths) {
        int s = path[0], d = path[1], w = path[2];
        mountainPath[s].push_back({d, w});
        mountainPath[d].push_back({s, w});
    }

    for (int gate : gates) isGate[gate] = true;
    for (int summit : summits) isSummit[summit] = true;
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    for (int gate : gates) {
        pq.push({0, gate});
        minIntensity[gate] = 0;
    }
    int bestSummit = -1, bestIntensity = INT32_MAX;

    while (!pq.empty()) {
        auto [curIntensity, curNode] = pq.top();
        pq.pop();

        if (curIntensity > minIntensity[curNode]) continue;

        if (isSummit[curNode]) {
            if (curIntensity < bestIntensity || (curIntensity == bestIntensity && curNode < bestSummit)) {
                bestSummit = curNode;
                bestIntensity = curIntensity;
            }
            continue;
        }
        for (auto& [nextNode, weight] : mountainPath[curNode]) {
            if (isGate[nextNode]) continue;
            int newIntensity = max(curIntensity, weight);

            if (newIntensity < minIntensity[nextNode]) {
                minIntensity[nextNode] = newIntensity;
                pq.push({newIntensity, nextNode});
            }
        }
    }

    return {bestSummit, bestIntensity};
}
