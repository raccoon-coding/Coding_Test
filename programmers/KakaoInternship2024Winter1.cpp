#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

vector<string> split(string str, char Delimiter) {
    
    istringstream iss(str);
    string buffer;
    vector<string> result;
 
    while (getline(iss, buffer, Delimiter)) {
        
        result.push_back(buffer);
    }
 
    return result;
}

int solution(vector<string> friends, vector<string> gifts) {
    
    int answer = 0;
    
    vector<vector<int>> exchangeGift (friends.size(), vector<int> (friends.size(), 0));
    vector<int> giftNumber (friends.size(), 0);
    vector<int> nextMonthGiftNumber(friends.size(), 0);
    
    for(int i = 0; i < gifts.size(); i++) {
        
        vector<string> temp = split(gifts[i], ' ');
        int giveName, getName;
        
        for(int j = 0; j < friends.size(); j++) {
            
            if(temp[0] ==  friends[j]) {
                
                giveName = j;
            } else if(temp[1] == friends[j]) {
                
                getName = j;
            }
        }
        
        exchangeGift[giveName][getName]++;
        giftNumber[giveName]++;
        giftNumber[getName]--;
    }
    
    for(int x = 0; x < friends.size(); x++){
        
        for(int y = 0; y < friends.size(); y++) {
            
            if(x >= y) {
                continue;
            }
            
            if(exchangeGift[x][y] == exchangeGift[y][x]) {
                
                if(giftNumber[x] > giftNumber[y]) {
                    
                    nextMonthGiftNumber[x]++;
                } else if(giftNumber[x] < giftNumber[y]) {
                    nextMonthGiftNumber[y]++;
                }
            } else if(exchangeGift[x][y] > exchangeGift[y][x]) {
                
                nextMonthGiftNumber[x]++;
            } else if(exchangeGift[x][y] < exchangeGift[y][x]) {
                
                nextMonthGiftNumber[y]++;
            }   
        }
    }
    
    answer = nextMonthGiftNumber[0];
    
    for(int i = 1; i < friends.size(); i++) {
        
        if(answer < nextMonthGiftNumber[i]) {
            
            answer = nextMonthGiftNumber[i];
        }
    }
    
    return answer;
}