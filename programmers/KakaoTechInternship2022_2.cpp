#include <string>
#include <vector>
#include <iostream>

using namespace std;

int queue1Index, queue2Index;
long queue1Sum, queue2Sum;

bool sumEqual(vector<int>& queue1, vector<int>& queue2) {
    
    if(queue1Sum > queue2Sum) {
        queue1Sum -= queue1[queue1Index];
        queue2Sum += queue1[queue1Index];
        queue2.push_back(queue1[queue1Index++]);
    } else if (queue1Sum < queue2Sum) {
        queue1Sum += queue2[queue2Index];
        queue2Sum -= queue2[queue2Index];
        queue1.push_back(queue2[queue2Index++]);
    } else {
        return true;
    }
    
    return false;
}

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -1;
    int maxTry = (queue1.size() + queue2.size()) * 2;
    
    queue1Index = 0;
    queue2Index = 0;
    
    queue1Sum = 0;
    queue2Sum = 0;
    
    for(auto a : queue1) {
        queue1Sum += a;
    }
    
    for(auto a : queue2) {
        queue2Sum += a;
    }
    
    for(int x = 0; x < maxTry; x++) {
        if(sumEqual(queue1, queue2)) {
            answer = x;
            break;
        }
    }
    return answer;
}