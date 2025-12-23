#include <iostream>
#include <string>

using namespace std;

int main_1094() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int X;
    cin >> X;

    // X의 이진수에서 1의 개수 = 필요한 막대 조각 개수
    cout << __builtin_popcount(X) << endl;
    return 0;
}