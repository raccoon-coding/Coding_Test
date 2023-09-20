#include <iostream>
#include <vector>

using namespace std;
void BinarySearch_2343(vector<int> &A, int N, int M, int Start, int End);

void BinarySearch_2343(vector<int> &A, int N, int M, int Start, int End){
    while(Start <= End) {
        int mid = (End + Start) / 2;
        int sum = 0, count = 0;
        for(int i = 0; i < N; i++){
            if(sum + A[i] > mid){
                count++;
                sum = 0;
            }
            sum += A[i];
        }
        if (sum != 0)
            count++;
        if (count > M)
            Start = mid + 1;
        else
            End = mid - 1;
    }
    cout << Start << "\n";
}

int main_2343(){
    int N = 0, M = 0, Start = 0, End = 0;
    cin >> N >> M;
    vector<int> A_2343(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> A_2343[i];
        if(Start < A_2343[i])
            Start = A_2343[i];
        End += A_2343[i];
    }
    BinarySearch_2343(A_2343, N, M, Start, End);
    return 0;
}