#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main_11404()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> updateGraph(N+1, vector<int> (N+1));

    for(int i = 0; i < N + 1; i++) {
        for (int j = 0; j < N + 1; j++) {
            if (i == j)
                updateGraph[i][j] = 0;
            else
                updateGraph[i][j] = 10000001;
        }
    }

    for(int i = 0; i < M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(updateGraph[a][b] > c){
            updateGraph[a][b] = c;
        }
    }

    for(int k = 1; k < N + 1; k++){
        for(int i = 1; i < N + 1; i++){
            for(int j = 1; j < N + 1; j++){
                if(updateGraph[i][k] + updateGraph[k][j] < updateGraph[i][j]){
                    updateGraph[i][j] = updateGraph[i][k] + updateGraph[k][j];
                }
            }
        }
    }

    for(int i = 1; i < N + 1; i++){
        for(int j = 1; j < N + 1; j++){
            if(updateGraph[i][j] == 10000001){
                cout << "0 ";
            }
            else {
                cout << updateGraph[i][j] << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}