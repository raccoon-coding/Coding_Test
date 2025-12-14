#include <iostream>
#include <algorithm>
using namespace std;
vector<int> A_1920, B_1920;

void searchFunction_1920(int N, int M){
    for(int i = 0; i < M; i++){
        bool find = false;
        int object = B_1920[i];
        int start = 0, end = N - 1;
        while(start <= end){
            int middle = (start + end) / 2;
            if(A_1920[middle] > object)
                end = middle - 1;
            else if (A_1920[middle] < object)
                start = middle + 1;
            else {
                find = true;
                break;
            }
        }
        if(find)
            cout << 1 << "\n";
        else
            cout << 0 << "\n";
    }
}

int main_search_1920(){
    int N;
    cin >> N;
    A_1920.resize(N);
    for(int i = 0; i < N; i++)
        cin >> A_1920[i];
    int M;
    cin >> M;
    B_1920.resize(M);
    for(int i = 0; i < M; i++)
        cin >> B_1920[i];
    sort(A_1920.begin(), A_1920.end());
    searchFunction_1920(N ,M);
    return 0;
}