#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int range_15649 = 0;
int maxNumber_15649 = 0;
vector<int> sequence_15649;
vector<bool> numberCheck_15649;

void backTracking_15649(int index) {

    if(index == range_15649 + 1) {

        for(int i = 1; i <= range_15649; i++) {

            cout << sequence_15649[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = 1; i <= maxNumber_15649; i++) {

        if(!numberCheck_15649[i]){

            numberCheck_15649[i] = true;
            sequence_15649[index] = i;
            backTracking_15649(index + 1);
            numberCheck_15649[i] = false;
        }
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> maxNumber_15649 >> range_15649;

    sequence_15649.resize(range_15649 + 1, 0);
    numberCheck_15649.resize(maxNumber_15649 + 1, false);

    backTracking_15649(1);

    return 0;
}