#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

/**
 * 첫째 줄에 건물의 종류 수 N(1 ≤ N ≤ 500)이 주어진다.
 * 다음 N개의 줄에는 각 건물을 짓는데 걸리는 시간과 그 건물을 짓기 위해 먼저 지어져야 하는 건물들의 번호가 주어진다.
 * 건물의 번호는 1부터 N까지로 하고, 각 줄은 -1로 끝난다고 하자.
 * 각 건물을 짓는데 걸리는 시간은 100,000보다 작거나 같은 자연수이다. 모든 건물을 짓는 것이 가능한 입력만 주어진다.
 * 위상 정렬이 꼭 필요함
 * */

using namespace std;
vector<int> timeStructure_1516;
vector<long> resultTime_1516;
vector<vector<int>> preStructure_1516;
vector<int> indegree_1516;

int main_1516(){
    int N = 0;
    cin >> N;

    preStructure_1516.resize(N + 1);
    resultTime_1516.resize(N + 1, 0L);
    timeStructure_1516.resize(N + 1);
    indegree_1516.resize(N + 1);

    for(int i = 1; i <= N; i++) {
        int time = 0, temp = 0;
        cin >> time;
        timeStructure_1516[i] = time;
        while(cin >> temp){
            if(temp == -1)
                break;
            preStructure_1516[temp].push_back(i);
            indegree_1516[i]++;
        }
    }

    queue<int> queue;
    for(int i = 1; i <= N; i++){
        if(indegree_1516[i] == 0) {
            queue.push(i);
        }
    }

    while (!queue.empty()) {
        int now = queue.front();
        queue.pop();
        for (int next : preStructure_1516[now]) {
            indegree_1516[next]--;
            resultTime_1516[next] = max(resultTime_1516[next], resultTime_1516[now] + timeStructure_1516[now]);
            if (indegree_1516[next] == 0) {
                queue.push(next);
            }
        }
    }

    for(int i = 1; i <= N; i++)
        cout << resultTime_1516[i] + timeStructure_1516[i] << "\n";

    return 0;
}