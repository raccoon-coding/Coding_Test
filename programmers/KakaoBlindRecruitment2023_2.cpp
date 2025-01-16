#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    int deliver=0, pickUp=0, count=0;
    
    for(int x=n-1; x>=0; x--){
        
        deliver-=deliveries[x];
        pickUp-=pickups[x];
        
        while(1){
            if(deliver>=0 && pickUp>=0) {
                break;
            }
            deliver+=cap;
            pickUp+=cap;
            count++;
        }
        
        answer+=(x+1)*2*count;
        count=0;
    }
    return answer;
}