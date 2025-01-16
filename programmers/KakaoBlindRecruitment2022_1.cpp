#include <string>
#include <sstream>
#include <vector>

/*
같은 유저를 여러번 신고해도 한번으로 간주 (True, false)로 구현
K번 이상 신고되었다면 정지 후 신고한 유저에게 결과 메일 발송
*/

using namespace std;

int n;

vector<vector<bool>> reportUser;
vector<int> reportCount;
vector<int> postEmail;

void split(vector<string> id_list, string input) {
    
    stringstream ss;
    string stringBuffer;
    ss.str(input);
    getline(ss, stringBuffer, ' ');
    string callUser = stringBuffer;
    getline(ss, stringBuffer, ' ');
    string getUser = stringBuffer;
    
    int callIndex, getIndex;
    
    for(int x = 0; x < id_list.size(); x++) {
        if(id_list[x] == callUser) {
            callIndex = x;
        } else if(id_list[x] == getUser) {
            getIndex = x;
        }
    }
    if(!reportUser[callIndex][getIndex]){
        reportUser[callIndex][getIndex] = true;
        reportCount[getIndex]++;
    }
}

void counting(int k) {
    for(int x = 0; x < n; x++) { // 신고 당한 사람
        for(int y = 0; y < n; y++) { // 신고한 사람
            if(reportUser[y][x] && reportCount[x] >= k) {
                postEmail[y]++;
            }
        }
    }
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    
    n = id_list.size();
    reportUser.resize(n, vector<bool> (n, false));
    reportCount.resize(n, 0);
    postEmail.resize(n, 0);
    
    for(auto s : report) {
        split(id_list, s);
    }
    
    counting(k);
    return postEmail;
}