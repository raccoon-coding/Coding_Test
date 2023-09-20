#include <iostream>
#include <algorithm>
using namespace std;

long find_k_number_1300(long N, long K) {
    long start = 1, end = K, ans = 0;
    while(start <= end){
        long middle = (start + end) / 2;
        int count = 0;
        for(int i = 1; i <= N; i++){
            count += min(middle/i , N);
        }
        if (count < K)
            start = middle + 1;
        else{
            ans = middle;
            end = middle - 1;
        }
    }
    return ans;
}

int main_search_1300(){
    long N, K;
    cin >> N >> K;
    cout << find_k_number_1300(N, K) << "\n";
    return 0;
}