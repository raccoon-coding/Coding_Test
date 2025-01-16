#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

/*
1. 시작할 때, 플레이어는 n/3카드를 가지고 시작
2. 1라운드마다 2장씩 카드를 받고, 뽑은 카드 중 코인을 소모해서 가질 수 있음
3. 버리는 카드의 적힌 수의 합이 n+1이 되도록 카드 2장을 내고, 다음 라운드에 진출 가능. 
4. 없으면 게임 종료
결국 완전 탐색을 꾸준히 돌리는데, BFS로 진행하는게 좋을 듯 함. (카드 버리는걸 한정해야 함.)
버리는 카드 셋은 항상 일정하므로, vector<pair<int, int>>에 모아서 시간 복잡도를 줄여야 한다.
*/

using namespace std;

int playGame(int coin);
void setCard(vector<int> cards);
int matchCard(int maxIndex, int coin);

int n, startCardIndex;
vector<int> set, handCard;

int playGame(int coin) {
    
    int round = 1;
    int maxRound = (n - startCardIndex) / 2 + 1;
    int roundCoin = coin;
    for(int i = 1; i < maxRound; i++) {
        int getCardIndex = startCardIndex + i * 2;
        roundCoin = matchCard(getCardIndex, roundCoin);
        if(roundCoin == -1) {
            return round;
        }
        round++;
    }
    return maxRound;
}

int matchCard(int maxIndex, int coin) {
    for(int x = 0; x < maxIndex; x++) {
        int y = set[x];
        if(y >= maxIndex) {
            continue;
        }
        if(handCard[x] == 1 && handCard[y] == 1) {
            handCard[x] = -1;
            handCard[y] = -1;
            return coin;
        } else if(handCard[x] == 1 && handCard[y] == 0 && coin >= 1){
            handCard[x] = -1;
            handCard[y] = -1;
            return coin - 1;
        } else if(handCard[x] == 0 && handCard[y] == 0 && coin >= 2) {
            handCard[x] = -1;
            handCard[y] = -1;
            return coin - 2;
        }
    }
    return -1;
}

void setCard(vector<int> cards) {
    for(int x = 0; x < n; x++) {
        for(int y = x + 1; y < n; y++) {
            if(cards[x] + cards[y] == n + 1) {
                set[x] = y;
                set[y] = x;
                break;
            }
        }
    }
}

int solution(int coin, vector<int> cards) {
    
    int answer = 0;
    
    n = cards.size();
    startCardIndex = n/3;
    set.resize(cards.size(), -1);
    handCard.resize(n, 0);
    
    fill(handCard.begin(), handCard.begin() + startCardIndex, 1);
    setCard(cards);
    answer = playGame(coin);
    
    return answer;
}