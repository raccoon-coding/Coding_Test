#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
vector<int> parent_1717;
void Union_1717(int a, int b);
int Find_1717(int a);

void Union_1717(int a, int b){
    a = Find_1717(a);
    b = Find_1717(b);
    if(a == b){
        return;
    }
    else
        parent_1717[b] = a;
}

int Find_1717(int a) {
    if(parent_1717[a] == a)
        return a;
    else
        return parent_1717[a] = Find_1717(parent_1717[a]);
}

int main_1717(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N = 0, M = 0;
    cin >> N >> M;
    parent_1717.resize(N + 1);

    for(int i = 0; i <= N; i++)
        parent_1717[i] = i;

    for(int i = 0; i < M; i++){
        int product, a, b;
        cin >> product >> a >> b;
        if(product == 0)
            Union_1717(a, b);
        else {
            if (Find_1717(a) == Find_1717(b))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}