#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
// operator[0] = +
// operator[1] = -
// operator[2] = *
// operator[3] = /

vector<int> operators_14888;
vector<long> numbers_14888;
int numberCount_14888;
long maxResult_14888 = -1000000000, minResult_14888 = 1000000000;

void backtracking_14888(int index, long currentResult);

void backtracking_14888(int index, long currentResult) {

    if (index == numberCount_14888) { 
        // 모든 숫자를 다 사용한 경우
        maxResult_14888 = max(maxResult_14888, currentResult);
        minResult_14888 = min(minResult_14888, currentResult);
        return;
    }

    // 연산자를 하나씩 사용하면서 다음 숫자와 연산
    for (int i = 0; i < 4; i++) {
        if (operators_14888[i] > 0) { // 사용할 연산자가 남아있는지 확인
            operators_14888[i]--; // 연산자 사용

            if (i == 0) {
                backtracking_14888(index + 1, currentResult + numbers_14888[index]);
            } else if (i == 1) {
                backtracking_14888(index + 1, currentResult - numbers_14888[index]);
            } else if (i == 2) {
                backtracking_14888(index + 1, currentResult * numbers_14888[index]);
            } else {
                // 나눗셈은 정수 나눗셈만 수행
                if (currentResult < 0) {
                    backtracking_14888(index + 1, -(-currentResult / numbers_14888[index]));
                } else {
                    backtracking_14888(index + 1, currentResult / numbers_14888[index]);
                }
            }
            operators_14888[i]++; // 연산자 복구
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> numberCount_14888;
    numbers_14888.resize(numberCount_14888);
    operators_14888.resize(4);

    for (int i = 0; i < numberCount_14888; i++) {
        cin >> numbers_14888[i];
    }

    for (int i = 0; i < 4; i++) {
        cin >> operators_14888[i]; // 덧셈, 뺄셈, 곱셈, 나눗셈 연산자 수
    }

    backtracking_14888(1, numbers_14888[0]); // 첫 번째 숫자는 미리 사용

    cout << maxResult_14888 << '\n' << minResult_14888 << '\n';

    return 0;
}