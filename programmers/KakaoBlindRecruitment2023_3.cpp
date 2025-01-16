#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int maxUsers = 0;
int maxRevenue = 0;
int discount[] = {10, 20, 30, 40};

void calculateResult(vector<vector<int>> users, vector<int> emoticons, vector<int> discounts) {
    int usersCount = 0;
    int revenue = 0;

    // 모든 유저에 대해 계산
    for (auto user : users) {
        int minDiscount = user[0];  // 이 유저가 구매할 최소 할인율
        int limitPrice = user[1];   // 이 유저의 구매 포기 기준 가격
        int totalPrice = 0;

        // 이모티콘 구매 비용 계산
        for (int i = 0; i < emoticons.size(); i++) {
            if (discounts[i] >= minDiscount) {
                totalPrice += emoticons[i] * (100 - discounts[i]) / 100;
            }
        }

        // 기준 가격을 넘으면 서비스 가입
        if (totalPrice >= limitPrice) {
            usersCount++;
        } else {
            revenue += totalPrice;
        }
    }

    // 이모티콘 플러스 서비스 가입자 수 최댓값을 우선, 그 다음 판매액
    if (usersCount > maxUsers) {
        maxUsers = usersCount;
        maxRevenue = revenue;
    } else if (usersCount == maxUsers && revenue > maxRevenue) {
        maxRevenue = revenue;
    }
}

void discountEmoticons(vector<vector<int>> users, vector<int> emoticons, vector<int> discounts, int depth) {
    if (depth == emoticons.size()) {
        calculateResult(users, emoticons, discounts);
        return;
    }

    // 각 이모티콘에 대해 4가지 할인율을 적용하는 백트래킹
    for (int i = 0; i < 4; i++) {
        discounts[depth] = discount[i];
        discountEmoticons(users, emoticons, discounts, depth + 1);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> discounts(emoticons.size(), 0);
    discountEmoticons(users, emoticons, discounts, 0);
    return {maxUsers, maxRevenue};
}