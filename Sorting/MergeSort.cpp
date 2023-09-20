#include <iostream>
#include <vector>

using namespace std;
vector<int> Number;
vector<int> Sort;
void mergesort(int start, int end);
void merge(int start, int end);

void merge(int start, int end){
    int mid = (start + end) / 2;
    int i = start;
    int j = mid + 1;
    int k = start;

    while (i <= mid && j <= end) {
        if (Number[i] <= Number[j]) {
            Sort[k++] = Number[i++];
        } else {
            Sort[k++] = Number[j++];
        }
    }
    while (i <= mid) {
        Sort[k++] = Number[i++];
    }
    while (j <= end) {
        Sort[k++] = Number[j++];
    }
    for (k = start; k <= end; k++) {
        Number[k] = Sort[k];
    }
}

void mergesort(int start, int end){
    if(start < end){
        int mid = (start + end) / 2;
        mergesort(start, mid);
        mergesort(mid + 1, end);
        merge(start, end);
    }
}

int main () {
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        int temp = 0;
        cin >> temp;
        Number.push_back(temp);
    }
    Sort.resize(N);
    mergesort(0, N - 1);
    for(int i = 0; i < N; i++) {
        cout << Number[i] << "\n";
    }
    return 0;
}