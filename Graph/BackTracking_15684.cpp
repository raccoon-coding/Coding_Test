#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct position_15684 {
    int x, y;
};

int N_15684, M_15684, H_15684, MIN_15684 = 4;

bool playOneGame_15684(vector<vector<int>> &graph, int startNode) {
    int x = startNode;
    for(int i = 1; i <= H_15684; i++) {
        if(graph[i][x] == 0) continue;
        else if(graph[i][x] == 1) x++;
        else if(graph[i][x] == -1) x--;
    }
    return x == startNode;
}

void playGame_15684(vector<vector<int>> &graph, int depth) {
    for (int i = 1; i <= N_15684; i++) {
        if (!playOneGame_15684(graph, i)) return;
    }
    MIN_15684 = min(MIN_15684, depth);
}

void findGraph_15684(vector<vector<int>> &graph, int depth, position_15684 pos) {
    if (depth >= MIN_15684) return;
    
    playGame_15684(graph, depth);

    if (depth == 3) return;

    int nx = pos.x;
    int ny = pos.y;
    for(int y = ny; y <= H_15684; y++) {
        int start = 1;
        if(y == ny) start = nx;
        for(int x = start; x < N_15684; x++) {
            if (graph[y][x] == 0 && graph[y][x + 1] == 0) {
                if (x > 1 && graph[y][x - 1] == 1) continue;
                
                graph[y][x] = 1;
                graph[y][x + 1] = -1;
                
                findGraph_15684(graph, depth + 1, {x, y});
                
                graph[y][x] = 0;
                graph[y][x + 1] = 0;
            }
        }
    }
    return;
}

int main_15684() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N_15684 >> M_15684 >> H_15684;

    vector<vector<int>> graph(H_15684 + 1, vector<int>(N_15684 + 1, 0));

    for (int i = 0; i < M_15684; i++) {
        int x, y;
        cin >> y >> x;
        graph[y][x] = 1;
        graph[y][x + 1] = -1;
    }

    findGraph_15684(graph, 0, {1, 1});

    if(MIN_15684 == 4) MIN_15684 = -1;
    cout << MIN_15684 << endl;
    return 0;
}