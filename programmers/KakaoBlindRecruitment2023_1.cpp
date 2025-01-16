#include <string>
#include <iostream>
#include <sstream>
#include <vector>

/*
모든 달은 28일까지 존재한다고 가정한다.
terms에서 스플릿 진행 후, 약관과 일을 저장한 벡터로 변환한다.
오늘이 저장된 배열과 각 가입 일자를 빼서, 몇달이 차이나는지 확인하는 함수가 필요하다.
위 함수에서 나온 값이 각 약관의 저장 달과 비교하여 높으면 삭제, 아닌경우 저장하는 로직이 필요하다.
*/

using namespace std;

void splitTerms(string input);
void splitTimeAndTerm(string input, int index);
vector<int> splitTime(string input);
bool getMouth(vector<int> focus, int term);

vector<pair<string, int>> saveTerms;
vector<int> todayVector;
vector<int> answer;

void splitTerms(string input) {

	stringstream ss;		// stringstream 객체인 ss 선언
	string stringBuffer;	// stringstream에서 문자열 자를 때마다 임시로 저장하는 변수
	ss.str(input);			// ss에 문자열 삽입
	
    // ss에서 dlim 직전까지의 문자열을 잘라서 stringBuffer에 저장. ss가 빌 때까지 실행
	while (getline(ss, stringBuffer, ' '))	{
		string first = stringBuffer;
        getline(ss, stringBuffer, ' ');
        int time = stoi(stringBuffer);
        saveTerms.push_back({first, time});
	}
}

void splitTimeAndTerm(string input, int index) {
    
    stringstream ss;
    string stringBuffer;
    ss.str(input);
    
    while(getline(ss, stringBuffer, ' ')) {
        string day = stringBuffer;
        getline(ss, stringBuffer, ' ');
        
        string term = stringBuffer;
        
        vector<int> time = splitTime(day);
        
        for(int x = 0; x < saveTerms.size(); x++) {
            if(saveTerms[x].first == term) {
                if(getMouth(time, saveTerms[x].second)) {
                    answer.push_back(index);
                    break;
                }
            }
        }
    }
}

vector<int> splitTime(string input) {
    
    vector<int> result;
    
    stringstream ss;
    string stringBuffer;
    ss.str(input);
    
    while(getline(ss, stringBuffer, '.')){
        
        result.push_back(stoi(stringBuffer));
    }
    return result;
}

bool getMouth(vector<int> focus, int term) {
    
    vector<int> time(3);
    
    for(int x = 0; x < 3; x++) {
        int temp = todayVector[x] - focus[x];
        if(temp < 0 && x == 1) {
            time[0]--;
            time[1] = temp + 12;
        } else if(temp < 0 && x == 2){
            time[1]--;
            time[2] = temp + 28;
        } else {
            time[x] = temp;
        }
    }
    if(time[1] + time[0] * 12 >= term) {
        return true;
    } else {
        return false;
    }
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    
    todayVector = splitTime(today);
    for(auto a : terms) {
        splitTerms(a);
    }
    
    for(int x = 0; x < privacies.size(); x++) {
        splitTimeAndTerm(privacies[x], x + 1);
    }
    return answer;
}