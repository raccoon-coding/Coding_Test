#include <iostream>
#include <string>
using namespace std;

void DFS_2023(int prime, int N);
bool IsPrime_2023(int number);

void DFS_2023(int prime, int N){
    string digit = to_string(prime);
    if(digit.size() == N)
        cout << prime << "\n";

    for(int i = 1; i < 10; i = i + 2){
        if(IsPrime_2023(prime * 10 + i))
            DFS_2023(prime * 10 + i, N);
        else
            continue;
    }
}
// 왜 틀린 코드인지 모름, 확인 해야함
//void DFS_2023(int prime, int N){
//    for(int i = 1; i < 10; i = i + 2){
//        int taget = prime * 10 + i;
//        if(IsPrime_2023(taget)){
//            string digit = to_string(taget);
//            if(digit.size() == N)
//                cout << taget << "\n";
//            else
//                DFS_2023(taget, N);
//        }
//        else
//            continue;
//    }
//}

bool IsPrime_2023(int number){
    for(int i = 2; i <= number / 2; i++){
        if(number % i == 0)
            return false;
    }
    return true;
}

int main_search_2023(){
    int N = 0;
    cin >> N;
    DFS_2023(2, N);
    DFS_2023(3, N);
    DFS_2023(5, N);
    DFS_2023(7, N);
    return 0;
}