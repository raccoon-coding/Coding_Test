#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct point{
    int x, y, count;
    string list;
};

int dy[4] = {0, -1, 1, 0};
int dx[4] = {1, 0, 0, -1};
char listup[4] = {'d', 'l', 'r', 'u'};

string solution(int n, int m, int x, int y, int r, int c, int k) {
    int min_dist = abs(x - r) + abs(y - c);
    
    if (min_dist > k || (k - min_dist) % 2 != 0) {
        return "impossible";
    }
    
    string path = "";
    
    while (k > 0) {
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 1 || nx > n || ny < 1 || ny > m) {
                continue;
            }
            
            int new_dist = abs(nx - r) + abs(ny - c);
            if (new_dist <= k - 1) {
                path += listup[i];
                x = nx;
                y = ny;
                k--;
                break;
            }
        }
    }
    
    return path;
}