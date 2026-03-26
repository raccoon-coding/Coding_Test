#include <iostream>

using namespace std;

int main()
{
    int n,  k;
    cin >> n >> k;

    int result = 0;

    while (__builtin_popcount(n) > k)
    {
        int lowBit = n & -n;
        result += lowBit;
        n += lowBit;
    }
    cout << result << endl;
    return 0;
}