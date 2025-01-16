#include <string>
#include <vector>
#include <iostream>

/*
RT
CF 3(콘형 1점)
JM 4(점수 없음)
AN 1(어피치평 3점)

1 : 매우 비동의 ~ 7 : 매우 동의
*/

using namespace std;
// 1 index R, T
// 2 index C, F
// 3 index J, M
// 4 index A, N

void verifyOne(vector<int> count, string survey, int choice) {
    int score = choice - 4;
    if(survey == "RT" || survey == "TR") {
        if(survey == "RT") {
            if(score == 0) {
                return;
            } else if(score > 0) {
                count[0] -= score;
            } else {
                count[0] -= score;
            }
        } else if(survey == "TR"){
            if(score == 0) {
                return;
            } else if(score > 0) {
                count[0] += score;
            } else {
                count[0] += score;
            }
        }
    }
}

void verifyTwo(vector<int> count, string survey, int choice) {
    int score = choice - 4;
    if(survey == "CF" || survey == "FC") {
        if(survey == "CF") {
            if(score == 0) {
                return;
            } else if(score > 0) {
                count[1] -= score;
            } else {
                count[1] -= score;
            }
        } else if(survey == "FC"){
            if(score == 0) {
                return;
            } else if(score > 0) {
                count[1] += score;
            } else {
                count[1] += score;
            }
        }
    }
}

void verifyThree(vector<int> count, string survey, int choice) {
    int score = choice - 4;
    if(survey == "JM" || survey == "MJ") {
        if(survey == "JM") {
            if(score == 0) {
                return;
            } else if(score > 0) {
                count[2] -= score;
            } else {
                count[2] -= score;
            }
        } else if(survey == "MJ"){
            if(score == 0) {
                return;
            } else if(score > 0) {
                count[2] += score;
            } else {
                count[2] += score;
            }
        }
    }
}

void verifyFour(vector<int> count, string survey, int choice) {
    int score = choice - 4;
    if(survey == "AN" || survey == "NA") {
        if(survey == "AN") {
            if(score == 0) {
                return;
            } else if(score > 0) {
                count[3] -= score;
            } else {
                count[3] -= score;
            }
        } else if(survey == "NA"){
            if(score == 0) {
                return;
            } else if(score > 0) {
                count[3] += score;
            } else {
                count[3] += score;
            }
        }
    }
}

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    vector<int> count;
    count.resize(4, 0);
    
    for(int x = 0; x < survey.size(); x++) {
        verifyOne(count, survey[x], choices[x]);
        verifyTwo(count, survey[x], choices[x]);
        verifyThree(count, survey[x], choices[x]);
        verifyFour(count, survey[x], choices[x]);
    }
    
    vector<string> result;
    
    if(count[0] >= 0) {
        result.push_back("R");
    } else if(count[0] < 0) {
        result.push_back("T");
    }
    if(count[1] >= 0) {
        result.push_back("C");
    } else if(count[1] < 0) {
        result.push_back("F");
    }
    if(count[2] >= 0) {
        result.push_back("J");
    } else if(count[2] < 0) {
        result.push_back("M");
    }
    if(count[3] >= 0) {
        result.push_back("A");
    } else if(count[3] < 0){
        result.push_back("N");
    }
    
    answer = result[0] + result[1] + result[2] + result[3];
    
    return answer;
}