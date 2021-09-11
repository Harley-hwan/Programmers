#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

bool bs(vector<int> stones, int mid, int k) {
    int cnt = 0;

    // stones 순회
    for (int i = 0; i < stones.size(); i++) {
        // 결과가 0이하면 카운트
        if (stones[i] - mid <= 0)   cnt++;

        // 0이 아니면 다시 카운트 0으로 초기화하고 다시 연속된 다리 개수 카운트.
        else    cnt = 0;

        if (cnt >= k) return true;
    }
    return false;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    // start = 1, end = 배열에서 max값
    int start = 1, end = *max_element(stones.begin(), stones.end());

    while(start <= end) {   // 이분 탐색 진행
        int mid = (start + end) / 2;

        if (bs(stones, mid, k))     end = mid - 1;
        else                        start = mid + 1;
    }
    return start;   // 징검다리를 건널 수 있는 사람의 수
}



// ----------------------------------------------------
// 완전 탐색 (시간 초과)

// int solution(vector<int> stones, long long k) {
//     long long answer = 0;
//     int dif = 0;
//     while(1){
//         for (int i = 0; i < stones.size(); i++) {
//             if (dif >= k) return answer;
//             if (stones[i] == 0) {
//                 dif++;
//                 //cout << "dif: " << dif << endl;
//                 continue;
//             }
//             stones[i]--;
//             dif = 0;
//             //cout << "stones[" << i << "]: " << stones[i] << endl;
//         }
//         answer++;
//     }
//     return answer;
// }


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> stones = {2, 4, 5, 3, 2, 1, 4, 2, 5, 1};
    int k = 3;

    cout << solution(stones, k) << endl;

    return 0;
}