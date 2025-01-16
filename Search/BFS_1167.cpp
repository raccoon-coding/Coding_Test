#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


// #include iostream
// istringstream ss(str);
// while(getline(ss, temp, ""))
//      vector.push_back(temp);

typedef pair<int, int> edge_1167;
static vector<vector<edge_1167>> A_1167;
static vector<bool> visited_1167;
static vector<int> m_distance_1167;
void BFS_1167(int node);

void BFS_1167(int node){
    // BFS를 진행하기 위해 queue 자료구조 사용
    queue<int> myqueue;
    myqueue.push(node);
    visited_1167[node] = true;
    // BFS를 하면서 거리 벡터에 거리만큼 계속 더해감
    while (!myqueue.empty()){
        int now_node = myqueue.front();
        myqueue.pop();
        for (edge_1167 i : A_1167[now_node]){
            if(!visited_1167[i.first]){
                visited_1167[i.first] = true;
                myqueue.push(i.first);
                m_distance_1167[i.first] = m_distance_1167[now_node] + i.second;
            }
        }
    }
}

int main_Search_1167() {
    // 입력 받고 2차원 벡터에 데이터 넣기
    int N;
    cin >> N;
    A_1167.resize(N + 1);
    for (int i = 0; i < N; i++) {
        int S = 0;
        cin >> S;
        while (true){
            int E, V;
            cin >> E;
            if(E == -1) break;
            cin >> V;
            A_1167[S].push_back(edge_1167(E, V));
        }
    }
    // 거리와 방문 벡터를 선언하고, 이 벡터를 초기화한다
    m_distance_1167 = vector<int>(N + 1, 0);
    visited_1167 = vector<bool>(N+1, false);
    // 노드 1번부터 BFS_1167 시작
    BFS_1167(1);
    /* 노드 1번에서 거리가 가장 먼 Max를 찾는다. 
     * 이때 이 Max Node는 가장 거리가 큰 2개의 Node 중 하나이다.
     * 이유는 어떤 Node에서 시작해도 가장 거리가 먼 2개의 Node 중 하나가 가장 거리가 멀 테니까*/
    int Max = 1;
    for (int i = 2; i < N+1; i++) {
        if (m_distance_1167[Max] < m_distance_1167[i])
            Max = i;
    }
    // 다시 거리와 방문 노드를 초기화
    fill(m_distance_1167.begin(), m_distance_1167.end(), 0);
    fill(visited_1167.begin(), visited_1167.end(), false);
    // 가장 먼 거리에 있는 노드부터 다시 BFS_1167 시작
    BFS_1167(Max);
    // 거리 순서대로 정렬 후 결과
    sort(m_distance_1167.begin(), m_distance_1167.end());
    cout << m_distance_1167[N] << '\n';
    return 0;
}