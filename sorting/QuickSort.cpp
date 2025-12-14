#include <iostream>
#include <vector>

using namespace std;
vector<int> Number_quick;
void quicksort(int start, int end);

void quicksort(int start, int end){
    if(start >= end)
        return;
    int pivot = Number_quick[start];
    int i = start, j = end;
    while(i <= j){
        while (i <= end && Number_quick[i] <= pivot)
            i++;
        while (j > start && Number_quick[j] >= pivot)
            j--;

        if (i < j) {
            swap(Number_quick[i], Number_quick[j]);
        }
    }
    swap(Number_quick[start], Number_quick[j]);
    quicksort(start, j - 1);
    quicksort(j + 1, end);
}

int main_quicksort() {
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        int temp = 0;
        cin >> temp;
        Number_quick.push_back(temp);
    }
    quicksort(0, N - 1);
    for(int i = 0; i < N; i++) {
        cout << Number_quick[i] << "\n";
    }
    return 0;
}