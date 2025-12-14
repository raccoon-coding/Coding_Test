#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N_1062, K_1062, Max_1062 = 0;

vector<string> words_1062;
bool alpha_1062[26];

void countWord_1062() {
    int count = 0;
    for(int i = 0; i < words_1062.size(); i++) {
        bool check = false;
        for(int j = 0; j < words_1062[i].size(); j++) {
            int index = words_1062[i][j] - 'a';
            if(!alpha_1062[index]){
                check = true;
                break;
            }
        }
        if(!check) count++;
    }
    Max_1062 = max(Max_1062, count);
    return;
}

void findCombination_1062(int startIndex, int depth) {
    if(depth == K_1062) {
        countWord_1062();
        return;
    }

    for(int i = startIndex; i < 26; i++) {
        if(alpha_1062[i]) continue;
        alpha_1062[i] = true;
        findCombination_1062(i + 1, depth + 1);
        alpha_1062[i] = false;
    }
}

void learnAlpha_1062() {
    int index = 'a';

    alpha_1062['a' - index] = true;
    alpha_1062['n' - index] = true;
    alpha_1062['t' - index] = true;
    alpha_1062['i' - index] = true;
    alpha_1062['c' - index] = true;

    findCombination_1062(1, 5);
}

int main_1062() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N_1062 >> K_1062;

    words_1062.resize(N_1062);

    for(int i = 0; i < N_1062; i++) {
        cin >> words_1062[i];
    }
    
    if(K_1062 < 5) {
        cout << '0' << endl;
        return 0;
    }

    learnAlpha_1062();

    cout << Max_1062 << endl;

    return 0;
}