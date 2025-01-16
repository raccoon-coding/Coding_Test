#include <string>
#include <iostream>
#include <vector>

/*
같은 점수에서 라이언이 더 많이 맞추어야 점수 획득 가능
만약 둘다 한발도 못 맞추었다면, 점수 획득 불가
목표 : 가장 큰 점수로 라이언이 이기는 방법
가장 높은 점수를 얻는 것이 필요하지만, 결국 모든 방법을 서치해야 함.
여기서 중요한 것은 어피치보다 한발만 더 쏘면 된다.
29
*/

using namespace std;

int maxScore;
vector<int> answer;

void dfs(vector<int> apichi, vector<int> winner, int depth, int count) {
    
    if(depth == 11 || count == 0) {
        int sum = 0, apichiScore = 0;
        for(int x = 0; x < 11; x++) {
            if(winner[x] > apichi[x]) {
                sum += 10 - x;
            } else if (winner[x] == 0 && apichi[x] == 0) {
                continue;
            } else if(winner[x] <= apichi[x]) {
                apichiScore += 10 - x;
            }
        }
        int totalScore = sum - apichiScore;
        if(totalScore > 0 && maxScore < totalScore) {
            maxScore = totalScore;
            answer = winner;
        } 
        else if(totalScore > 0 && maxScore == totalScore) {
            for(int x = 10; x > -1; x--) {
                if(answer[x] < winner[x]) {
                    answer = winner;
                    break;
                } else if (answer[x] > winner[x]) {
                    break;
                }
            }
        }
    } else {
        dfs(apichi, winner, depth + 1, count);
        if(count >= apichi[depth] + 1) {
            winner[depth] = apichi[depth] + 1;
            count -= apichi[depth] + 1;
            dfs(apichi, winner, depth + 1, count);
        }else if (count > 0 && depth == 10) {
            winner[depth] = count;
            dfs(apichi, winner, depth + 1, 0);
        }
    }
}

vector<int> solution(int n, vector<int> info) {
    maxScore = 0;
    dfs(info, vector<int> (11, 0), 0, n);
    if(answer.size() == 0) {
        return {-1};
    }
    return answer;
}