#include <iostream>
#include <vector>

//using namespace std;
//vector<int> Number;
//void quicksort(int start, int end);
//
//void quicksort(int start, int end){
//    if(start >= end)
//        return;
//    int pivot = Number[start];
//    int i = start, j = end;
//    while(i <= j){
//        while (i <= end && Number[i] <= pivot)
//            i++;
//        while (j > start && Number[j] >= pivot)
//            j--;
//
//        if (i < j) {
//            swap(Number[i], Number[j]);
//        }
//    }
//    swap(Number[start], Number[j]);
//    quicksort(start, j - 1);
//    quicksort(j + 1, end);
//}
//
//int main_quicksort () {
//    int N;
//    cin >> N;
//    for(int i = 0; i < N; i++) {
//        int temp = 0;
//        cin >> temp;
//        Number.push_back(temp);
//    }
//    quicksort(0, N - 1);
//    for(int i = 0; i < N; i++) {
//        cout << Number[i] << "\n";
//    }
//    return 0;
//}