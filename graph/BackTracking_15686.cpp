#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct position_15686 {
    int x, y;
};

int N_15686, M_15686;
int MIN_15686 = INT16_MAX;
bool selected_15686[13]; // M의 최대값이 13
vector<position_15686> house;
vector<position_15686> chicken;
vector<position_15686> pickChicken;

int distance_15686(position_15686 a, position_15686 b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

void calculation_15686() {
    int tempResult = 0;
    for(int i = 0; i < house.size(); i++) {
        int minTemp = INT16_MAX;
        for(int j = 0; j < M_15686; j++) {
            int tempDistance = distance_15686(house[i], pickChicken[j]);
            minTemp = min(minTemp, tempDistance);
        }
        tempResult += minTemp;
    }
    MIN_15686 = min(MIN_15686, tempResult);
}

void findCombination_15686(int x, int m) {
    if(m == M_15686) calculation_15686();

    for(int i = x; i < chicken.size(); i++) {
        if(selected_15686[i]) continue;
        selected_15686[i] = true;
        pickChicken.push_back({chicken[i].x, chicken[i].y});
        findCombination_15686(i, m + 1);
        selected_15686[i] = false;
        pickChicken.pop_back();
    }
}

int main_15686() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N_15686 >> M_15686;

    for(int y = 0; y < N_15686; y++) {
        for(int x = 0; x < N_15686; x++) {
            int temp;
            cin >> temp;
            if(temp == 1) house.push_back({x, y});
            else if(temp == 2) chicken.push_back({x, y});
        }
    }

    findCombination_15686(0, 0);

    cout << MIN_15686 << "\n";
    return 0;
}