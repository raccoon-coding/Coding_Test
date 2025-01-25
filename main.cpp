#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, K, Max = 0;

vector<string> words;
bool alpha[26];

void countWord() {
    int count = 0;
    for(int i = 0; i < words.size(); i++) {
        bool check = false;
        for(int j = 0; j < words[i].size(); j++) {
            int index = words[i][j] - 'a';
            if(!alpha[index]){
                check = true;
                break;
            }
        }
        if(!check) count++;
    }
    Max = max(Max, count);
    return;
}

void findCombination(int depth) {
    if(depth == K) {
        countWord();
        return;
    }

    for(int i = 0; i < 26; i++) {
        if(alpha[i]) continue;
        alpha[i] = true;
        findCombination(depth + 1);
        alpha[i] = false;
    }
}

void learnAlpha() {
    int index = 'a';

    alpha['a' - index] = true;
    alpha['n' - index] = true;
    alpha['t' - index] = true;
    alpha['i' - index] = true;
    alpha['c' - index] = true;

    findCombination(5);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    words.resize(N);

    for(int i = 0; i < N; i++) {
        cin >> words[i];
    }
    
    if(K < 5) {
        cout << '0' << endl;
        return 0;
    }

    learnAlpha();

    cout << Max << endl;

    return 0;
}