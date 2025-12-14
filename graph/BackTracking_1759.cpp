#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int L_1759, C_1759;
vector<char> alpha_1759;
vector<char> password_1759;
bool selected_1759[15];

int countVowel_1759() {
    int count = 0;
    for(int x = 0; x < L_1759; x++) {
        if(password_1759[x] == 'a') count++;
        else if(password_1759[x] == 'e') count++;
        else if(password_1759[x] == 'i') count++;
        else if(password_1759[x] == 'o') count++;
        else if(password_1759[x] == 'u') count++;
    }
    return count;
}

bool isHaveTwoConsonant_1759() {
    int count = countVowel_1759();
    if(L_1759 - count > 1 && count > 0) return true;
    return false;
}

void findCombination_1759(int x, int l) {
    if(l == L_1759) {
        if(isHaveTwoConsonant_1759()) {
            for(int i = 0; i < L_1759; i++) {
                cout << password_1759[i];
            }
            cout << endl;
        }
    }

    for(int i = x; i < C_1759; i++) {
        if(selected_1759[i]) continue;
        selected_1759[i] = true;
        password_1759.push_back(alpha_1759[i]);
        findCombination_1759(i, l + 1);
        selected_1759[i] = false;
        password_1759.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> L_1759 >> C_1759;

    for(int x = 0; x < C_1759; x++) {
        char temp;
        cin >> temp;
        alpha_1759.push_back(temp);
    }

    sort(alpha_1759.begin(), alpha_1759.end());

    findCombination_1759(0, 0);
    return 0;
}