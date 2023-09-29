#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

/**
 * 크루스칼 알고리즘을 사용하여 최소 신장 트리를 만들어 낸 후, 그 값을 엣지 가중치의 총 합에서 빼자!!
 * */

using namespace std;
void calculator();
void Union(int a, int b);
int Find(int a);
bool compare(const tuple <int, int, long> &a, const tuple <int, int, long> &b);

vector<tuple<int, int, int>> edges;
vector<int> parent;
int result;

void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if(a != b) {
        parent[b] = a;
    }
}

int Find(int a){
    if(parent[a] == a)
        return a;
    else
        return parent[a] = Find(parent[a]);
}

bool compare(const tuple <int, int, long> &a, const tuple <int, int, long> &b){
    return get<2>(a) < get<2>(b);
}

void calculator() {
    for(auto & edge : edges){
        int start_node = get<0>(edge);
        int next_node = get<1>(edge);
        int weight = get<2>(edge);

        if(Find(start_node) != Find(next_node) && weight != 0) {
            Union(start_node, next_node);
            result -= weight;
        }
    }
}

int main(){
    int N = 0;
    result = 0;
    cin >> N;
    parent.resize(N);
    for(int i = 0; i < N; i++)
        parent[i] = i;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            char temp;
            cin >> temp;
            if('a' <= temp && temp <= 'z')
                edges.push_back(make_tuple(i, j, temp - 'a' + 1));
            else if (temp == '0')
                edges.push_back(make_tuple(i, j, 0));
            else
                edges.push_back(make_tuple(i, j, temp - 'A' + 27));
            result += get<2>(edges[edges.size() - 1]);
        }
    }
    sort(edges.begin(), edges.end(), compare);
    calculator();
    for(int i = 1; i < N; i++){
        if(Find(i) != Find(0)){
            cout << -1 << "\n";
            return 0;
        }
    }
    cout << result << "\n";
    return 0;
}