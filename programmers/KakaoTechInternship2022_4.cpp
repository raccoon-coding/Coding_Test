#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems) {
    int max_alp = 0, max_cop = 0;
    
    for (auto& problem : problems) {
        max_alp = max(max_alp, problem[0]);
        max_cop = max(max_cop, problem[1]);
    }
    
    alp = min(alp, max_alp);
    cop = min(cop, max_cop);
    
    vector<vector<int>> dp(151, vector<int>(151, INT32_MAX));
    dp[alp][cop] = 0;
    
    for (int i = alp; i <= max_alp; ++i) {
        for (int j = cop; j <= max_cop; ++j) {
            if (i + 1 <= 150) {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
            } if (j + 1 <= 150) {
                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
            }

            for (auto& problem : problems) {
                int req_alp = problem[0], req_cop = problem[1];
                int gain_alp = problem[2], gain_cop = problem[3], cost = problem[4];

                if (i >= req_alp && j >= req_cop) {
                    int new_alp = min(i + gain_alp, max_alp);
                    int new_cop = min(j + gain_cop, max_cop);
                    dp[new_alp][new_cop] = min(dp[new_alp][new_cop], dp[i][j] + cost);
                }
            }
        }
    }
    
    return dp[max_alp][max_cop];
}