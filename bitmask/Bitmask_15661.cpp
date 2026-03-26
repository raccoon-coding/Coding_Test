#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> v[i][j];

    int diff = INT_MAX;

    for (int mask = 1; mask < (1 << n) - 1; mask++)
    {
        int start = 0, link = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((mask & (1 << i)) && (mask & (1 << j)))
                    start += v[i][j];
                else if (!(mask & (1 << i)) && !(mask & (1 << j)))
                    link += v[i][j];
            }
        }

        diff = min(diff, abs(start - link));
    }

    cout << diff << '\n';
    return 0;
}
