#include <string>
#include <vector>
#include <iostream>

using namespace std;
int endday[8][2] = {{0, 0}, {5, 6}, {4, 5}, {3, 4}, {2, 3}, {1, 2}, {0, 1}, {6, 0}};

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    for(int i = 0; i < schedules.size(); i++) {
        int start = schedules[i];
        if(start % 100 + 10 >= 60) {
            start = start + 100 - 60 + 10;
        } else {
            start += 10;
        }
        vector<int> time = timelogs[i];
        int count = 0;
        for(int j = 0; j < 7; j++) {
            if(endday[startday][0] == j || endday[startday][1] == j) {
                continue;
            } else if(time[j] <= start) {
                count++;
            }
        }
        if(count == 5) {
            answer++;
        }
    }
    return answer;
}