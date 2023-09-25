#include <iostream>
#include <vector>
#include <climits>

using namespace std;
struct Edge_1219 {
    int from, to, cost;
};

vector<long> get_money_1219;
vector<long> city_price_1219;
vector<Edge_1219> edges_1219;
void count_edges_1219(int start_city, int N, int M);

void count_edges_1219(int start_city, int N, int M) {
    city_price_1219[start_city] = get_money_1219[start_city];
    for (int i = 0; i <= N + 100; i++) {
        for (int j = 0; j < M; j++) {
            int start = edges_1219[j].from;
            int end = edges_1219[j].to;
            int price = edges_1219[j].cost;
            if (city_price_1219[start] == LONG_MIN) continue;
            else if (city_price_1219[start] == LONG_MAX)
                city_price_1219[end] = LONG_MAX;
            else if (city_price_1219[end] < city_price_1219[start] + get_money_1219[end] - price) {
                city_price_1219[end] = city_price_1219[start] + get_money_1219[end] - price;
                if (i >= N - 1)
                    city_price_1219[end] = LONG_MAX;
                // Bellman-Ford 알고리즘
            }
        }
    }
}


int main_1219(){
    int N = 0, M = 0, start_city = 0, end_city = 0;
    cin >> N >> start_city >> end_city >> M;
    get_money_1219.resize(N);
    city_price_1219.resize(N, LONG_MIN);
    for (int i = 0; i < M; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        edges_1219.push_back({from, to, cost});
    }
    for (int i = 0; i < N; i++) {
        cin >> get_money_1219[i];
    }
    count_edges_1219(start_city, N, M);

    if (city_price_1219[end_city] == LONG_MIN) cout << "gg"<< "\n";
    else if (city_price_1219[end_city] == LONG_MAX) cout << "Gee" << "\n";
    else cout << city_price_1219[end_city] << "\n";

    return 0;
}