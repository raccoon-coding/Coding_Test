#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

/**
 * 크루스칼 알고리즘을 사용하여 최소 신장 트리를 만들어 낸 후, 그 값을 엣지 가중치의 총 합에서 빼자!!
 * */

using namespace std;
void calculator_1414();
void Union_1414(int a, int b);
int Find_1414(int a);
bool compare_1414(const tuple <int, int, long> &a, const tuple <int, int, long> &b);

vector<tuple<int, int, int>> edges_1414;
vector<int> parent_1414;
int result_1414;

void Union_1414(int a, int b){
    a = Find_1414(a);
    b = Find_1414(b);
    if(a != b) {
        parent_1414[b] = a;
    }
}

int Find_1414(int a){
    if(parent_1414[a] == a)
        return a;
    else
        return parent_1414[a] = Find_1414(parent_1414[a]);
}

bool compare_1414(const tuple <int, int, long> &a, const tuple <int, int, long> &b){
    return get<2>(a) < get<2>(b);
}

void calculator_1414() {
    for(auto & edge : edges_1414){
        int start_node = get<0>(edge);
        int next_node = get<1>(edge);
        int weight = get<2>(edge);

        if(Find_1414(start_node) != Find_1414(next_node) && weight != 0) {
            Union_1414(start_node, next_node);
            result_1414 -= weight;
        }
    }
}

int main_1414(){
    int N = 0;
    result_1414 = 0;
    cin >> N;
    parent_1414.resize(N);
    for(int i = 0; i < N; i++)
        parent_1414[i] = i;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            char temp;
            cin >> temp;
            if('a' <= temp && temp <= 'z')
                edges_1414.push_back(make_tuple(i, j, temp - 'a' + 1));
            else if (temp == '0')
                edges_1414.push_back(make_tuple(i, j, 0));
            else
                edges_1414.push_back(make_tuple(i, j, temp - 'A' + 27));
            result_1414 += get<2>(edges_1414[edges_1414.size() - 1]);
        }
    }
    sort(edges_1414.begin(), edges_1414.end(), compare_1414);
    calculator_1414();
    for(int i = 1; i < N; i++){
        if(Find_1414(i) != Find_1414(0)){
            cout << -1 << "\n";
            return 0;
        }
    }
    cout << result_1414 << "\n";
    return 0;
}