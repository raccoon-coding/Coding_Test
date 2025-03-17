#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

struct xy {
    int x, y;
};

vector<string> split(string input, char dim) {
    stringstream ss(input);
    vector<string> result;
    string stringbuffer;
    
    while (getline(ss, stringbuffer, dim)) {
        result.push_back(stringbuffer);
    }
    return result;
}

xy findParent(vector<vector<xy>>& parent, int x, int y) {
    if (parent[x][y].x == x && parent[x][y].y == y) {
        return {x, y};
    }
    return parent[x][y] = findParent(parent, parent[x][y].x, parent[x][y].y);
}

void mergeCells(int x1, int y1, int x2, int y2, 
                vector<vector<xy>>& parent, vector<vector<string>>& rule) {
    xy root1 = findParent(parent, x1, y1);
    xy root2 = findParent(parent, x2, y2);
    
    if (root1.x == root2.x && root1.y == root2.y) return;

    parent[root2.x][root2.y] = root1;

    if (rule[root1.x][root1.y] == "" && rule[root2.x][root2.y] != "") {
        rule[root1.x][root1.y] = rule[root2.x][root2.y];
    }
}

void unmergeCells(int x, int y, vector<vector<xy>>& parent, vector<vector<string>>& rule) {
    xy root = findParent(parent, x, y);
    string value = rule[root.x][root.y];

    vector<xy> toReset;
    for (int i = 1; i <= 50; i++) {
        for (int j = 1; j <= 50; j++) {
            xy find = findParent(parent, i, j);
            if (find.x == root.x && find.y == root.y) {
                toReset.push_back({i, j});
            }
        }
    }

    for (xy c : toReset) {
        parent[c.x][c.y] = {c.x, c.y};
        rule[c.x][c.y] = "";
    }

    rule[x][y] = value;
}

vector<string> solution(vector<string> commands) {
    vector<string> answer;
    vector<vector<string>> rule(51, vector<string>(51, ""));
    vector<vector<xy>> parent(51, vector<xy>(51));

    for (int i = 1; i <= 50; i++) {
        for (int j = 1; j <= 50; j++) {
            parent[i][j] = {i, j};
        }
    }

    for (string command : commands) {
        vector<string> temp = split(command, ' ');

        if (temp[0] == "UPDATE") {
            if (temp.size() == 4) {
                int x = stoi(temp[1]);
                int y = stoi(temp[2]);
                xy parentCell = findParent(parent, x, y);
                rule[parentCell.x][parentCell.y] = temp[3];
            } else {
                for (int i = 1; i <= 50; i++) {
                    for (int j = 1; j <= 50; j++) {
                        if (rule[i][j] == temp[1]) {
                            rule[i][j] = temp[2];
                        }
                    }
                }
            }
        } 
        else if (temp[0] == "MERGE") {
            int x1 = stoi(temp[1]);
            int y1 = stoi(temp[2]);
            int x2 = stoi(temp[3]);
            int y2 = stoi(temp[4]);
            mergeCells(x1, y1, x2, y2, parent, rule);
        } 
        else if (temp[0] == "UNMERGE") {
            int x = stoi(temp[1]);
            int y = stoi(temp[2]);
            unmergeCells(x, y, parent, rule);
        } 
        else if (temp[0] == "PRINT") {
            int x = stoi(temp[1]);
            int y = stoi(temp[2]);
            xy parentCell = findParent(parent, x, y);
            if (rule[parentCell.x][parentCell.y] == "") {
                answer.push_back("EMPTY");
            } else {
                answer.push_back(rule[parentCell.x][parentCell.y]);
            }
        }
    }

    return answer;
}
