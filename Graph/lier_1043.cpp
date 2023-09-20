#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> party;
vector<bool> fact_human;
vector<int> parent;
void Union(int a, int b);
int find(int a);

void Union(int a, int b){
    a = find(a);
    b = find(b);
    if (a != b) {
        parent[b] = a;
    }
}

int find(int a){
    if (a == parent[a])
        return a;
    else
        return parent[a] = find(parent[a]);
}

int main_1043(){
    int N = 0, M = 0;
    cin >> N >> M;
    party.resize(M);
    fact_human.resize(N + 1, false);
    parent.resize(N + 1);

    int fact = 0;
    cin >> fact;
    for(int i = 0; i < fact; i++){
        int a;
        cin >> a;
        fact_human[a] = true;
    }

    for(int i = 0; i < M; i++){
        int number = 0;
        int first = 0;
        cin >> number;
        cin >> first;
        party[i].resize(number);
        party[i][0] = first;
        for(int j = 1; j < number; j++){
            int human = 0;
            cin >> human;
            party[i][j] = human;
        }
    }

    for(int i = 1; i < N + 1; i++)
        parent[i] = i;

    for (int i = 0; i < M; i++) {
        int firstPeople = party[i][0];
        for (int j = 1; j < party[i].size(); j++) {
            Union(firstPeople, party[i][j]);
        }
    }

    int result = 0;
    for(int i = 0; i < M; i++) {
        bool check = false;
        int first = party[i][0];
        for(int j = 1; j < N; j++){
            if(fact_human[j]){
                if(find(first) == find(j)){
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