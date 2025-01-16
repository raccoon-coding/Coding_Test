#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

struct tiemOfCar {
    int hour, min, number;
    string state;
};

// 차량의 번호와 요금을 담은 구조체
struct minTimeOfCar {
    int number, min;
};

vector<minTimeOfCar> feesOfCars;
vector<tiemOfCar> cars;

bool compare(const minTimeOfCar& a, const minTimeOfCar& b) {
    return a.number < b.number;
}

// 문자열을 분리하는 함수
void split(string input) {
    string time, state;
    int number;
    stringstream ss(input);
    
    string stringBuffer;
    getline(ss, stringBuffer, ' ');
    time = stringBuffer;
    getline(ss, stringBuffer, ' ');
    number = stoi(stringBuffer);
    getline(ss, stringBuffer, ' ');
    state = stringBuffer;
    
    stringstream s(time);
    string buffer;
    
    getline(s, buffer, ':');
    int hour = stoi(buffer);
    getline(s, buffer, ':');
    int min = stoi(buffer);
    
    cars.push_back({hour, min, number, state});
}

void findFee(vector<int> fees) {
    for(size_t x = 0; x < cars.size(); x++) {
        int number = cars[x].number;
        bool check = false;
        if(cars[x].state == "OUT"){
            continue;
        }
        for(size_t y = x + 1; y < cars.size(); y++) {
            if(cars[x].number != cars[y].number) {
                continue;
            } else {
                int minTime = cars[y].min - cars[x].min + (cars[y].hour - cars[x].hour) * 60;
                bool checkVector = false;
                for(auto &a : feesOfCars) {
                    if(a.number == number) {
                        a.min += minTime;
                        checkVector = true;
                        break;
                    }
                }
                if(!checkVector){
                    feesOfCars.push_back({number, minTime});
                }
                check = true;
                break;
            }
        }
        if(!check) {
            int minTime = 59 - cars[x].min + (23 - cars[x].hour) * 60;
            bool checkVector = false;
            for(auto &a : feesOfCars) {
                if(a.number == number) {
                    a.min += minTime;
                    checkVector = true;
                    break;
                }
            }
            if(!checkVector){
                feesOfCars.push_back({number, minTime});
            }
        }
    }   
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    for(auto& record : records) {
        split(record);
    }
    
    findFee(fees);
    
    sort(feesOfCars.begin(), feesOfCars.end(), compare);
    
    for(auto& feeCar : feesOfCars) {
        int fee = fees[1];
        if(feeCar.min > fees[0]) {
            if((feeCar.min - fees[0]) % fees[2] != 0) {
                fee += ((feeCar.min - fees[0]) / fees[2] + 1) * fees[3];
            } else {
                fee += ((feeCar.min - fees[0]) / fees[2]) * fees[3];
            }
        }
        answer.push_back(fee);
    }
    
    return answer;
}