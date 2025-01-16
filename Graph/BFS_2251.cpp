#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

typedef pair<int, int> compare_2251;
void BFS_2251();
int Sender_2251[] = {0, 0, 1, 1, 2, 2};
int Receiver_2251[] = {1, 2, 0, 2, 0, 1};
bool visited_2251[201][201];
bool answer_2251[201];
int bucket_2251[3];

void BFS_2251(){
    queue<compare_2251> queue;
    queue.push(make_pair(0,0));
    visited_2251[0][0] = true;
    answer_2251[bucket_2251[2]] = true;
    while (!queue.empty()) {
        compare_2251 p = queue.front();
        queue.pop();
        int A = p.first;
        int B = p.second;
        int C = bucket_2251[2] - A - B;
        for (int k = 0; k < 6; k++) { // A->B, A->C, B->A, B->C, C->A, C->B 6
            int next[] = { A, B, C };
            next[Receiver_2251[k]] += next[Sender_2251[k]];
            next[Sender_2251[k]] = 0;
            if (next[Receiver_2251[k]] > bucket_2251[Receiver_2251[k]]) {
                next[Sender_2251[k]] = next[Receiver_2251[k]] - bucket_2251[Receiver_2251[k]];
                next[Receiver_2251[k]] = bucket_2251[Receiver_2251[k]];
            }
            if (!visited_2251[next[0]][next[1]]) {
                visited_2251[next[0]][next[1]] = true;
                queue.push(make_pair(next[0], next[1]));
                if (next[0] == 0) {
                    answer_2251[next[2]] = true;
                }
            }
        }
    }
}

int main_2251()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i = 0; i < 3; i++)
        cin >> bucket_2251[i];
    BFS_2251();

    for (int i = 0; i < 201; i++) {
        if (answer_2251[i]) cout << i << " ";
    }

    return 0;
}
