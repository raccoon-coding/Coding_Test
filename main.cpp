#include <iostream>
#include <cmath>
#include <queue>

/*
 * 각각 부피가 A, B, C(1≤A, B, C≤200) 리터인 세 개의 물통이 있다.
 * 처음에는 앞의 두 물통은 비어 있고, 세 번째 물통은 가득(C 리터) 차 있다.
 * 이제 어떤 물통에 들어있는 물을 다른 물통으로 쏟아 부을 수 있는데, 이때에는 한 물통이 비거나, 다른 한 물통이 가득 찰 때까지 물을 부을 수 있다.
 * 이 과정에서 손실되는 물은 없다고 가정한다.
 * 이와 같은 과정을 거치다보면 세 번째 물통(용량이 C인)에 담겨있는 물의 양이 변할 수도 있다.
 * 첫 번째 물통(용량이 A인)이 비어 있을 때, 세 번째 물통(용량이 C인)에 담겨있을 수 있는 물의 양을 모두 구해내는 프로그램을 작성하시오.
 * 첫째 줄에 세 정수 A, B, C가 주어진다.
 * 첫째 줄에 공백으로 구분하여 답을 출력한다.
 * 각 용량은 오름차순으로 정렬한다.
 * 일단 A, B, C를 모두 들고 가나, 이 3개간의 차이를 계산한 후, (3개의 차이가 나옴)
8 9 10
 * */

using namespace std;

typedef pair<int, int> compare;
void BFS();
int Sender[] = {0, 0, 1, 1, 2, 2};
int Receiver[] = {1, 2, 0, 2, 0, 1};
bool visited[201][201];
bool answer[201];
int now[3];

void BFS(){
    queue<compare> queue;
    queue.push(make_pair(0,0));
    visited[0][0] = true;
    answer[now[2]] = true;
    while (!queue.empty()) {
        compare p = queue.front();
        queue.pop();
        int A = p.first;
        int B = p.second;
        int C = now[2] - A - B;
        for (int k = 0; k < 6; k++) { // A->B, A->C, B->A, B->C, C->A, C->B 6
            int next[] = { A, B, C };
            next[Receiver[k]] += next[Sender[k]];
            next[Sender[k]] = 0;
            if (next[Receiver[k]] > now[Receiver[k]]) {
                next[Sender[k]] = next[Receiver[k]] - now[Receiver[k]];
                next[Receiver[k]] = now[Receiver[k]];
            }
            if (!visited[next[0]][next[1]]) {
                visited[next[0]][next[1]] = true;
                queue.push(make_pair(next[0], next[1]));
                if (next[0] == 0) {
                    answer[next[2]] = true;
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i = 0; i < 3; i++)
        cin >> now[i];
    BFS();

    for (int i = 0; i < 201; i++) {
        if (answer[i]) cout << i << " ";
    }

    return 0;
}
