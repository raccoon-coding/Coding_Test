#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, half;

vector<vector<int>> sumA, sumB;
vector<pair<vector<int>, vector<int>>> diceIndices;
vector<vector<pair<int, int>>> countSumA, countSumB;

void sumDiceA(vector<vector<int>> &dice, int depth, int sum, int index) {
    
    if (depth == half) {
        
        sumA[index].push_back(sum);
        return;
    }
    
    int diceIndex = diceIndices[index].first[depth];
    
    for (int i = 0; i < 6; i++) {
        
        int newSum = sum + dice[diceIndex][i];
        sumDiceA(dice, depth + 1, newSum, index);
    }
}

void sumDiceB(vector<vector<int>> &dice, int depth, int sum, int index) {
    
    if (depth == half) {
        
        sumB[index].push_back(sum);
        return;
    }
    
    int diceIndex = diceIndices[index].second[depth];
    
    for (int i = 0; i < 6; i++) {
        
        int newSum = sum + dice[diceIndex][i];
        sumDiceB(dice, depth + 1, newSum, index);
    }
}

void counting() {
    
    for(int x = 0; x < sumA.size(); x++) {
        
        int count = 1;
        int number = sumA[x][0]; 
        
        for(int y = 1; y < sumA[x].size(); y++) { 
            
            if(number != sumA[x][y]) {
                
                countSumA[x].push_back({number, count});
                number = sumA[x][y];
                count = 1;
            } else {
                
                count++;
            }
        }
        
        // 마지막 number 처리
        countSumA[x].push_back({number, count});
    }
    
    for(int x = 0; x < sumB.size(); x++) {
        
        int count = 1;
        int number = sumB[x][0];
        
        for(int y = 1; y < sumB[x].size(); y++) {
            
            if(number != sumB[x][y]) {
                
                countSumB[x].push_back({number, count});
                number = sumB[x][y];
                count = 1;
            } else {
                
                count++;
            }
        }
        
        // 마지막 number 처리
        countSumB[x].push_back({number, count});
    }
}

int compare() {
    
    int winIndex = 0, maxWin = 0, minDraw = INT16_MAX;
    
    for(int x = 0; x < countSumA.size(); x++) {
        
        int win = 0, draw = 0;
        for(int y = 0; y < countSumA[x].size(); y++) {
            
            int sum = countSumA[x][y].first;
            int count = countSumA[x][y].second;
            int winGame = 0, drawGame = 0;
            for(int z = 0; z < countSumB[x].size(); z++) {
                
                if(sum > countSumB[x][z].first) {
                    
                    winGame += count * countSumB[x][z].second;
                } else if(sum == countSumB[x][z].first){
                    
                    drawGame += count * countSumB[x][z].second;
                } else {
                    
                    break;
                }
            }
            win += winGame;
            draw += drawGame;
        }
        if (win > maxWin || (win == maxWin && draw < minDraw)) {
            
            maxWin = win;
            minDraw = draw;
            winIndex = x;
        }
    }
    return winIndex;
}

vector<int> solution(vector<vector<int>> dice) {
    
    vector<int> answer;
    
    n = dice.size(); // 주사위의 개수
    half = n / 2; // A와 B가 가져갈 주사위의 수
    
    vector<int> maskDice(n, 0);
    fill(maskDice.end() - half, maskDice.end(), 1);
    
    do {
        
        vector<int> diceNumberA, diceNumberB;
        
        for(int i = 0; i < n; i++) {
            
            if(maskDice[i] == 1) {
                
                diceNumberA.push_back(i);
            } else {
                
                diceNumberB.push_back(i);
            }
        }
        
        diceIndices.push_back({diceNumberA, diceNumberB});
    } while (next_permutation(maskDice.begin(), maskDice.end()));
    
    sumA.resize(diceIndices.size(), vector<int> ());
    sumB.resize(diceIndices.size(), vector<int> ());
    countSumA.resize(diceIndices.size(), vector<pair<int, int>> ());
    countSumB.resize(diceIndices.size(), vector<pair<int, int>> ());
    
    for(int index = 0; index < diceIndices.size(); index++) {
        
        sumDiceA(dice, 0, 0, index);
        sumDiceB(dice, 0, 0, index);
        sort(sumA[index].begin(), sumA[index].end());
        sort(sumB[index].begin(), sumB[index].end());
    }
    
    counting();
    int index = compare();
    
    answer = diceIndices[index].first;
    
    for(int i = 0; i < answer.size(); i++) {
        
        answer[i]++;
    }
    
    return answer;
}