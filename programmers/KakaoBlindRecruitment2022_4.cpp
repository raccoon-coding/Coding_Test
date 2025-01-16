#include <string>
#include <vector>
#include <cmath>

/*
일단 N진수로 변환하는 함수 필요
0을 만나기 전까지 천천히 10진수로 찾아오기
이후, 소수인지 판단하기. (2, 3, 5, 7 등등 소수로 나눠봐야 하는데, 이 모음을 어떻게 찾을까나... )
*/
using namespace std;

vector<int> number;

bool isPrime(long long num) {
    if (num < 2) return false;
    for (long long i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}


void transfer(int n, int k) {
    if(n == 0){
        return;
    } else {
        number.push_back(n % k);
        transfer(n / k, k);
    }
}

int findResult() {
    long long currentNum = 0;
    int result = 0;
    
    for (int i = number.size() - 1; i >= 0; i--) {
        if (number[i] != 0) {
            currentNum = currentNum * 10 + number[i];
        } else {
            if (currentNum != 0 && isPrime(currentNum)) {
                result++;
            }
            currentNum = 0;
        }
    }
    
    if (currentNum != 0 && isPrime(currentNum)) {
        result++;
    }
    
    return result;
}

int solution(int n, int k) {
    int answer = -1;
    
    transfer(n, k);
    answer = findResult();
    
    return answer;
}