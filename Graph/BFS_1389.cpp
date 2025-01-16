#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
vector<vector<int>> human_graph_1389;
vector<bool> human_visited_1389;
vector<int> sum_human_1389;
void BFS_1389(int start);

void BFS_1389(int start){
    int Kevin = 0;
    for(int end = 1; end < human_graph_1389.size(); end++){
        if(end == start)
            continue;
        queue<pair<int, int>> myqueue;
        fill(human_visited_1389.begin(), human_visited_1389.end(), false);
        human_visited_1389[start] = true;
        int sum = 0;
        myqueue.emplace(start, sum);
        while(!myqueue.empty()){
            int now = myqueue.front().first;
            if(end == now){
                Kevin += myqueue.front().second;
                break;
            }
            sum = myqueue.front().second;
            myqueue.pop();
            for(int & i : human_graph_1389[now]){
                if(!human_visited_1389[i]){
                    myqueue.emplace(i, sum + 1);
                    human_visited_1389[i] = true;
                }
            }
        }
    }
    sum_human_1389[start] = Kevin;
}

int main_1389(){
    int N = 0, M = 0;
    cin >> N >> M;
    human_graph_1389.resize(N + 1);
    sum_human_1389.resize(N + 1);
    human_visited_1389.resize(N + 1, false);
    for (int i = 0; i < M; i++){
        int A = 0, B = 0;
        cin >> A >> B;
        human_graph_1389[A].push_back(B);
        human_graph_1389[B].push_back(A);
    }
    for(int i = 1; i <= N; i++){
        fill(human_visited_1389.begin(), human_visited_1389.end(), false);
        BFS_1389(i);
    }
    int least_human = 1;
    for(int i = 2; i <= N; i++){
        if(sum_human_1389[least_human] > sum_human_1389[i])
            least_human = i;
    }
    cout << least_human;
    return 0;
}