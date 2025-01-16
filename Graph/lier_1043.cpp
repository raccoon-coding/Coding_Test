#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> party_1043;
vector<bool> fact_human_1043;
vector<int> parent_1043;
void Union_1043(int a, int b);
int find_1043(int a);

void Union_1043(int a, int b){
    a = find_1043(a);
    b = find_1043(b);
    if (a != b) {
        parent_1043[b] = a;
    }
}

int find_1043(int a){
    if (a == parent_1043[a])
        return a;
    else
        return parent_1043[a] = find_1043(parent_1043[a]);
}

int main_1043(){
    int N = 0, M = 0;
    cin >> N >> M;
    party_1043.resize(M);
    fact_human_1043.resize(N + 1, false);
    parent_1043.resize(N + 1);

    int fact = 0;
    cin >> fact;
    for(int i = 0; i < fact; i++){
        int a;
        cin >> a;
        fact_human_1043[a] = true;
    }

    for(int i = 0; i < M; i++){
        int number = 0;
        int first = 0;
        cin >> number;
        cin >> first;
        party_1043[i].resize(number);
        party_1043[i][0] = first;
        for(int j = 1; j < number; j++){
            int human = 0;
            cin >> human;
            party_1043[i][j] = human;
        }
    }

    for(int i = 1; i < N + 1; i++)
        parent_1043[i] = i;

    for (int i = 0; i < M; i++) {
        int firstPeople = party_1043[i][0];
        for (int j = 1; j < party_1043[i].size(); j++) {
            Union_1043(firstPeople, party_1043[i][j]);
        }
    }

    int result = 0;
    for(int i = 0; i < M; i++) {
        bool check = false;
        int first = party_1043[i][0];
        for(int j = 1; j < N; j++){
            if(fact_human_1043[j]){
                if(find_1043(first) == find_1043(j)){
                    check = true;
                    break;
                }
            }
        }
        if(!check)
            result++;
    }

    cout << result << "\n";
    return 0;
}