#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct position_17406{
    int x, y;
};

int N_17406, M_17406, K_17406, MIN_17406 = INT16_MAX;
vector<vector<int>> rotateVector_17406;
vector<vector<int>> combination_17406;
bool visited_17406[6];

void findCombination_17406(vector<int> tempCombination, int depth) {
    if(depth == K_17406) {
        combination_17406.push_back(tempCombination);
        return;
    }

    for(int x = 0; x < K_17406; x++) {
        if(visited_17406[x]) continue;
        tempCombination.push_back(x);
        visited_17406[x] = true;
        findCombination_17406(tempCombination, depth + 1);
        visited_17406[x] = false;
        tempCombination.pop_back();
    }
}

int sum_17406(vector<vector<int>> &graph) {
    int tempMin = INT16_MAX;
    for(int y = 1; y <= N_17406; y++) {
        int sum = 0;
        for(int x = 1; x <= M_17406; x++) {
            sum += graph[y][x];
        }
        tempMin = min(tempMin, sum);
    }
    return tempMin;
}

void left_17406(vector<vector<int>> &graph, position_17406 startNode, position_17406 endNode) {
    int startX = startNode.x;
    int endX = endNode.x;
    int endY = endNode.y;
    for(int x = startX; x < endX; x++) {
        graph[endY][x] = graph[endY][x + 1];
    }
    return;
}

void up_17406(vector<vector<int>> &graph, position_17406 startNode, position_17406 endNode) {
    int startX = startNode.x;
    int startY = startNode.y;
    int endY = endNode.y;
    for(int y = startY; y < endY; y++) {
        graph[y][startX] = graph[y + 1][startX];
    }
    return;
}

void right_17406(vector<vector<int>> &graph, position_17406 startNode, position_17406 endNode) {
    int startX = startNode.x;
    int startY = startNode.y;
    int endX = endNode.x;
    for(int x = endX; x > startX; x--) {
        graph[startY][x] = graph[startY][x - 1];
    }
    return;
}

void down_17406(vector<vector<int>> &graph, position_17406 startNode, position_17406 endNode) {
    int startY = startNode.y;
    int endX = endNode.x;
    int endY = endNode.y;
    for(int y = endY; y > startY; y--) {
        graph[y][endX] = graph[y - 1][endX];
    }
    return;
}

void move_17406(vector<vector<int>> &graph, position_17406 startNode, position_17406 endNode) {
    int temp = graph[startNode.y][startNode.x];
    up_17406(graph, startNode, endNode);
    left_17406(graph, startNode, endNode);
    down_17406(graph, startNode, endNode);
    right_17406(graph, startNode, endNode);
    graph[startNode.y][startNode.x + 1] = temp;
    return;
}

void rotateMatrix_17406(vector<vector<int>> &graph, vector<int> &rotateTry) {
    int startY = rotateTry[0] - rotateTry[2], startX = rotateTry[1] - rotateTry[2];
    int endY = rotateTry[0] + rotateTry[2], endX = rotateTry[1] + rotateTry[2];

    for(int i = 0; i < rotateTry[2]; i++) {
        move_17406(graph, {startX + i, startY + i}, {endX - i, endY - i});
    }
    return;
}

void backTracking_17406(vector<vector<int>> &graph) {
    for(int i = 0; i < combination_17406.size(); i++) {
        vector<vector<int>> tempGraph = graph;
        for(int j = 0; j < combination_17406[i].size(); j++) {
            rotateMatrix_17406(tempGraph, rotateVector_17406[combination_17406[i][j]]);
        }

        MIN_17406 = min(MIN_17406, sum_17406(tempGraph));
    }
    return;
}

int main_17406() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N_17406 >> M_17406 >> K_17406;

    vector<vector<int>> graph(N_17406 + 1, vector<int> (M_17406 + 1, 0));

    for(int y = 1; y <= N_17406; y++) {
        for(int x = 1; x <= M_17406; x++) {
            cin >> graph[y][x];
        }
    }

    for(int i = 0; i < K_17406; i++) {
        vector<int> tempVector;
        for(int j = 0; j < 3; j++) {
            int temp;
            cin >> temp;
            tempVector.push_back(temp);
        }
        rotateVector_17406.push_back(tempVector);
    }

    findCombination_17406(vector<int> (), 0);
    backTracking_17406(graph);

    cout << MIN_17406 << endl;

    return 0;
}