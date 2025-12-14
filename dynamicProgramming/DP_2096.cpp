#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main_2096() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int maxDp[3] = {0}, minDp[3] = {0};

    for (int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;

        int tmpMax0 = max(maxDp[0], maxDp[1]) + a;
        int tmpMax1 = max({maxDp[0], maxDp[1], maxDp[2]}) + b;
        int tmpMax2 = max(maxDp[1], maxDp[2]) + c;

        int tmpMin0 = min(minDp[0], minDp[1]) + a;
        int tmpMin1 = min({minDp[0], minDp[1], minDp[2]}) + b;
        int tmpMin2 = min(minDp[1], minDp[2]) + c;

        maxDp[0] = tmpMax0;
        maxDp[1] = tmpMax1;
        maxDp[2] = tmpMax2;

        minDp[0] = tmpMin0;
        minDp[1] = tmpMin1;
        minDp[2] = tmpMin2;
    }

    int maxScore = max({maxDp[0], maxDp[1], maxDp[2]});
    int minScore = min({minDp[0], minDp[1], minDp[2]});

    cout << maxScore << " " << minScore << endl;
    return 0;
}