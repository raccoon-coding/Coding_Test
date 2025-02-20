#include <iostream>

using namespace std;

int staticNum_11726 = 10007, saveMax_11726 = 1;
int dp_11726[1001];

int main_11726() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    dp_11726[1] = 1;
    dp_11726[2] = 2;

    for (int i = 3; i <= n; i++) {
        dp_11726[i] = (dp_11726[i-1] + dp_11726[i-2]) % staticNum_11726;
    }

    cout << dp_11726[n] << "\n";
    return 0;
}