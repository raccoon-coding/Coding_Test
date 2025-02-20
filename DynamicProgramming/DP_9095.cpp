#include <iostream>
#include <vector>

using namespace std;

vector<int> memory_9095(12, 0);
vector<int> testCase_9095;

int main_9095() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    
    cin >> T;

    for(int i = 0; i < T; i++) {
        int temp;
        cin >> temp;
        testCase_9095.push_back(temp);
    }

    memory_9095[1] = 1;
    memory_9095[2] = 2;
    memory_9095[3] = 4;

    for(int i = 4; i <= 11; i++) {
        memory_9095[i] = memory_9095[i - 1] + memory_9095[i - 2] + memory_9095[i - 3];
    }

    for(int i = 0; i < T; i++) {
        cout << memory_9095[testCase_9095[i]] << endl;
    }

    return 0;
}