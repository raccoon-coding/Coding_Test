#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// Rolling Hash를 위한 큰 BASE 값 (64bit overflow hash 사용)
static const uint64_t BASE = 1315423911ULL;

// 입력값
int H, N;
uint64_t K;
vector<int> P;

// 해싱 전역 변수
vector<uint64_t> prefixHash;   // prefixHash[i] = arr[0..i-1]의 해시
vector<uint64_t> powerBase;    // powerBase[i] = BASE^i
vector<int> extP;              // 확장된 P 배열(반복된 형태)
long long maxNodes;            // 깊이 H일 때 노드 개수 = 2^(H-1)

// prefix hash + BASE 거듭제곱 테이블 생성
void build_hash(const vector<int>& arr) {
    int n = arr.size();

    // prefixHash[0] = 0, powerBase[0] = 1 초기화
    prefixHash.assign(n + 1, 0);
    powerBase.assign(n + 1, 1);

    // prefixHash[i+1] = prefixHash[i] * BASE + (arr[i] + 1)
    // powerBase[i+1]  = powerBase[i] * BASE
    for (int i = 0; i < n; i++) {
        prefixHash[i + 1] = prefixHash[i] * BASE + (uint64_t)(arr[i] + 1);
        powerBase[i + 1] = powerBase[i] * BASE;
    }
}

// 부분 구간 해시 얻기
// get_hash(l, r) = prefix[r+1] − prefix[l] * BASE^(r-l+1)
inline uint64_t get_hash(long long l, long long r) {
    return prefixHash[r + 1] - prefixHash[l] * powerBase[r - l + 1];
}

// 깊이 X에서 동일한 패턴이 K번 이상 등장하는지 검사
bool checkDepth(int X) {
    // 깊이 X에서 노드 개수 = 2^(X-1)
    long long nodeCount = (1LL << (X - 1));

    // 노드 수가 K보다 적으면 K번 등장 불가
    if (nodeCount < K) {
        return false;
    }

    // 깊이 X에서의 패턴 길이 L = N * 2^(H - X)
    long long L = (long long)N * (1LL << (H - X));

    unordered_map<uint64_t, uint64_t> freq;
    freq.reserve(nodeCount * 2);

    // 깊이 X의 i번째 노드는 확장배열에서 i*N 위치에서 시작
    for (long long i = 0; i < nodeCount; i++) {
        long long start = i * N;

        // 부분 문자열 해시 가져오기
        uint64_t h = get_hash(start, start + L - 1);

        // 해시값 카운트
        freq[h]++;

        // K번 이상 등장하면 True
        if (freq[h] >= K) {
            return true;
        }
    }

    // 어떤 패턴도 K번 이상 등장하지 않음
    return false;
}

// 메인 루틴
int main_16160() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> H >> N >> K;

    // P 입력
    P.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    // maxNodes = 2^(H-1)
    maxNodes = 1LL << (H - 1);

    // 충분히 긴 확장 배열 길이 계산
    // neededLength = N * 2^(H-1)
    long long neededLength = (long long)N * (1LL << (H - 1));

    // 필요한 만큼 P를 반복
    // repeatCount = neededLength / N + 여유분
    long long repeatCount = neededLength / N;
    repeatCount = repeatCount + 3;

    extP.reserve(repeatCount * N);

    // extP = P를 repeatCount번 반복
    for (long long i = 0; i < repeatCount; i++) {
        for (int x : P) {
            extP.push_back(x);
        }
    }

    // prefix hash 구성
    build_hash(extP);

    // 이분 탐색으로 최소 깊이 찾기
    int left = 1;
    int right = H;
    int answer = -1;

    while (left <= right) {
        int mid = (left + right) / 2;

        // mid 깊이에서 K번 이상 반복되는 패턴이 존재하는지 확인
        if (checkDepth(mid)) {
            answer = mid;     // mid는 가능한 정답
            right = mid - 1;  // 더 작은 깊이도 가능한지 탐색
        } else {
            left = mid + 1;   // 더 깊어야 K번 등장 가능
        }
    }

    cout << answer << "\n";
    return 0;
}