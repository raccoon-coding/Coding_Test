#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N_14889, MIN_14889 = INT16_MAX;
bool selected_14889[20];
vector<vector<int>> score_14889;
vector<int> teamA_14889, teamB_14889;

int absDiffence_14889(int x, int y) {
    return abs(x - y);
}

void diffScore_14889() {
    int teamAScore = 0;
    int teamBScore = 0;

    for(int i = 0; i < N_14889/2; i++) {
        for(int j = i + 1; j < N_14889/2; j++) {
            int teamAx = teamA_14889[i];
            int teamAy = teamA_14889[j];
            int teamBx = teamB_14889[i];
            int teamBy = teamB_14889[j];
            
            teamAScore += score_14889[teamAy][teamAx];
            teamAScore += score_14889[teamAx][teamAy];
            teamBScore += score_14889[teamBy][teamBx];
            teamBScore += score_14889[teamBx][teamBy];
        }
    }

    MIN_14889 = min(MIN_14889, absDiffence_14889(teamAScore, teamBScore));
    teamB_14889.clear();
}

void findCombinationTeamB_14889() {
    for(int x = 0; x < N_14889; x++) {
        if(selected_14889[x]) continue;
        teamB_14889.push_back(x);
    }

    diffScore_14889();
}

void findCombinationTeamA_14889(int x, int n) {
    if(n == N_14889/2) findCombinationTeamB_14889();

    for(int i = x; i < N_14889; i++) {
        if(selected_14889[i]) continue;
        selected_14889[i] = true;
        teamA_14889.push_back(i);
        findCombinationTeamA_14889(i, n + 1);
        selected_14889[i] = false;
        teamA_14889.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N_14889;

    score_14889.resize(N_14889, vector<int> (N_14889));

    for(int y = 0; y < N_14889; y++) {
        for(int x = 0; x < N_14889; x++) {
            cin >> score_14889[y][x];
        }
    }

    findCombinationTeamA_14889(0, 0);

    cout << MIN_14889 << "\n";
    
    return 0;
}