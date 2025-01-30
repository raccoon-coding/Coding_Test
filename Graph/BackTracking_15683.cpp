#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct position_15683 {
    int x, y;
};

struct cctv_position_15683 {
    position_15683 pos;
    int type;
};

int N_15683, M_15683, MIN_15683 = INT16_MAX;
vector<cctv_position_15683> cctv_15683;
vector<position_15683> block_15683;

void left_15683(vector<vector<int>> &graph, int nx, int ny) {
    if(nx == 0) return;
    for(int i = nx - 1; i >= 0; i--) {
        if(graph[ny][i] == 6) break;
        else if(graph[ny][i] == 0) graph[ny][i] = 8;
    }
}

void right_15683(vector<vector<int>> &graph, int nx, int ny) { 
    if(nx == M_15683 - 1) return;
    for(int i = nx + 1; i < M_15683; i++) {
        if(graph[ny][i] == 6) break;
        else if(graph[ny][i] == 0) graph[ny][i] = 8;
    }
}

void up_15683(vector<vector<int>> &graph, int nx, int ny) {
    if(ny == 0) return;
    for(int i = ny - 1; i >= 0; i--) {
        if(graph[i][nx] == 6) break;
        else if(graph[i][nx] == 0) graph[i][nx] = 8;
    }
}

void down_15683(vector<vector<int>> &graph, int nx, int ny) {
    if(ny == N_15683 - 1) return;
    for(int i = ny + 1; i < N_15683; i++) {
        if(graph[i][nx] == 6) break;
        else if(graph[i][nx] == 0) graph[i][nx] = 8;
    }
}

void setCctv_15683(vector<vector<int>> &graph, position_15683 cctvPos, int type, int dir) {
    int nx = cctvPos.x;
    int ny = cctvPos.y;
    if(type == 5) {
        left_15683(graph, nx, ny);
        right_15683(graph, nx, ny);
        up_15683(graph, nx, ny);
        down_15683(graph, nx, ny);
    } else if (type == 4) {
        if(dir == 0) {
            left_15683(graph, nx, ny);
            up_15683(graph, nx, ny);
            down_15683(graph, nx, ny);
        } else if(dir == 1) {
            left_15683(graph, nx, ny);
            right_15683(graph, nx, ny);
            down_15683(graph, nx, ny);
        } else if(dir == 2) {
            left_15683(graph, nx, ny);
            right_15683(graph, nx, ny);
            up_15683(graph, nx, ny);
        } else if (dir == 3) {
            right_15683(graph, nx, ny);
            up_15683(graph, nx, ny);
            down_15683(graph, nx, ny);
        }
    } else if (type == 3) {
        if(dir == 0) {
            right_15683(graph, nx, ny);
            up_15683(graph, nx, ny);
        } else if (dir == 1) {
            right_15683(graph, nx, ny);
            down_15683(graph, nx, ny);
        } else if (dir == 2) {
            left_15683(graph, nx, ny);
            down_15683(graph, nx, ny);
        } else if (dir == 3) {
            left_15683(graph, nx, ny);
            up_15683(graph, nx, ny);
        }
    } else if (type == 2) {
        if(dir == 0) {
            left_15683(graph, nx, ny);
            right_15683(graph, nx, ny);
        } else if(dir == 1) {
            up_15683(graph, nx, ny);
            down_15683(graph, nx, ny);
        }
    } else if (type == 1) {
        if(dir == 0) {
            left_15683(graph, nx, ny);
        } else if (dir == 1) {
            right_15683(graph, nx, ny);
        } else if (dir == 2) {
            up_15683(graph, nx, ny);
        } else if (dir == 3) {
            down_15683(graph, nx, ny);
        }
    }
    return;
}

void bfs_15683(vector<vector<int>> &graph, int depth) {
    if(depth == cctv_15683.size()) {
        int count = 0;
        for(int y = 0; y < N_15683; y++) {
            for(int x = 0; x < M_15683; x++) {
                if(graph[y][x] == 0) count++;
            }
        }
        MIN_15683 = min(MIN_15683, count);
        return;
    }

    for(int i = 0; i < 4; i++) {
        vector<vector<int>> tempGraph = graph;
        position_15683 pos = cctv_15683[depth].pos;
        int type = cctv_15683[depth].type;
        setCctv_15683(tempGraph, pos, type, i);
        bfs_15683(tempGraph, depth + 1);
        if(type == 5) break;
        else if (type == 2) {
            if(i == 1) break;
        }
    }
    return;
}

int main_15683() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N_15683 >> M_15683;

    vector<vector<int>> graph;
    graph.resize(N_15683, vector<int> (M_15683));

    for(int y = 0; y < N_15683; y++) {
        for(int x = 0; x < M_15683; x++) {
            cin >> graph[y][x];
            if(graph[y][x] != 6 && graph[y][x] != 0) cctv_15683.push_back({{x,y}, graph[y][x]});
        }
    }

    bfs_15683(graph, 0);
    cout << MIN_15683 << endl;

    return 0;
}