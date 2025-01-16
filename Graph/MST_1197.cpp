#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void combine_1197();
void Union_1197(int a, int b);
int Find_1197(int a);
vector<int> parent_1197;
vector<tuple<int, int, long>> Edges_1197;
long sum_result_1197;

/*
 * 최소 스패닝 트리 가중치 합 구하기
 * 이건 크루스칼 알고리즘을 사용해서 푸는 문제이다.
 * 크루스칼 알고리즘이란, 모든 간선을 가중치순으로 정렬한 후, 가중치가 작은 순서대로 간선을 연결해가면서 모든 노드가 연결되는지 확인하는 알고리즘이다.
 * 단 Cycle을 만들지 않기 위하여 Unoin, Find 알고리즘을 도입한다.
 * */

bool compare_1197(const tuple <int, int, long> &a, const tuple <int, int, long> &b){
    return get<2>(a) < get<2>(b);
}

void Union_1197(int a, int b) {
    a = Find_1197(a);
    b = Find_1197(b);
    if(a != b) {
        parent_1197[b] = a;
    }
}

int Find_1197(int a) {
    if(parent_1197[a] == a) return a;
    return parent_1197[a] = Find_1197(parent_1197[a]);
}

void combine_1197() {
    for(auto & Edge : Edges_1197){
        int start_node = get<0>(Edge);
        int next_node = get<1>(Edge);
        long weight = get<2>(Edge);

        if(Find_1197(start_node) != Find_1197(next_node)) {
            Union_1197(start_node, next_node);
            sum_result_1197 += weight;
        }
    }
}

int main_1197(){
    int N = 0, E = 0;
    sum_result_1197 = 0;
    cin >> N >> E;
    parent_1197.resize(N + 1);
    for(int i = 1; i <= N; i++) parent_1197[i] = i;
    for(int i = 0; i < E; i++){
        int now_node = 0, next_node = 0;
        long next_edge = 0;
        cin >> now_node >> next_node >> next_edge;
        Edges_1197.emplace_back(now_node, next_node, next_edge);
    }
    sort(Edges_1197.begin(), Edges_1197.end(), compare_1197);
    combine_1197();
    cout << sum_result_1197 << "\n";
    return 0;
}