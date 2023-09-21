#include <iostream>
#include <vector>

using namespace std;
vector<int> Number_merge;
vector<int> Sort_merge;
void mergesort(int start, int end);
void merge(int start, int end);

void merge(int start, int end){
    int mid = (start + end) / 2;
    int i = start;
    int j = mid + 1;
    int k = start;

    while (i <= mid && j <= end) {
        if (Number_merge[i] <= Number_merge[j]) {
            Sort_merge[k++] = Number_merge[i++];
        } else {
            Sort_merge[k++] = Number_merge[j++];
        }
    }
    while (i <= mid) {
        Sort_merge[k++] = Number_merge[i++];
    }
    while (j <= end) {
        Sort_merge[k++] = Number_merge[j++];
    }
    for (k = start; k <= end; k++) {
        Number_merge[k] = Sort_merge[k];
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

int main_merge () {
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        int temp = 0;
        cin >> temp;
        Number_merge.push_back(temp);
    }
    Sort_merge.resize(N);
    mergesort(0, N - 1);
    for(int i = 0; i < N; i++) {
        cout << Number_merge[i] << "\n";
    }
    return 0;
}