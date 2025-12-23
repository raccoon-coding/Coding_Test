#include <iostream>
#include <string>

using namespace std;

int main_11723() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int M;
    cin >> M;

    // 정수 S를 이용해 집합을 표현한다.
    // 비트 하나가 숫자 하나를 표현 → 1~20까지 사용
    // 예: S의 3번째 비트가 1이면 숫자 3이 집합에 포함된 것.
    int S = 0;

    while (M--) {
        string cmd;
        int x;
        cin >> cmd;

        if (cmd == "add") {
            cin >> x;
            // x번째 비트를 1로 설정한다.
            // OR 연산(|)은 해당 비트를 1로 “켜는” 역할.
            S |= (1 << x);
        }
        else if (cmd == "remove") {
            cin >> x;
            // x번째 비트를 0으로 만든다.
            // ~(1 << x)는 x번째 비트만 0, 나머지는 1인 마스크가 되고
            // AND(&) 연산을 하면 해당 비트만 꺼진다.
            S &= ~(1 << x);
        }
        else if (cmd == "check") {
            cin >> x;
            // S & (1 << x) 결과가 0이 아니라면 x가 포함된 것.
            if (S & (1 << x)) {
                cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
        }
        else if (cmd == "toggle") {
            cin >> x;
            // XOR(^) 연산은 해당 비트를 반전시킨다.
            // 1이면 0으로, 0이면 1으로 바뀌므로 toggle을 정확히 구현 가능.
            S ^= (1 << x);
        }
        else if (cmd == "all") {
            // 1~20번 비트까지 모두 1로 설정
            // (1 << 21) - 1  → 21비트 전체가 1인 값
            S = (1 << 21) - 1;
        }
        else if (cmd == "empty") {
            // 모든 비트를 0으로 만들어 공집합으로 초기화
            S = 0;
        }
    }
}