#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 프로그래머스 > 메뉴 리뉴얼 (2021 KAKAO BLIND RECRUITMENT)

unordered_map<string, int> MenuBoard[11];
int MaxCnt[11] = {0};

void comb(string str, int pos, string candi) {
    if (pos >= str.length()) {
        int len = candi.length();
        if (len >= 2) {
            MenuBoard[len][candi]++;    // 주문 횟수
            MaxCnt[len] = max(MaxCnt[len], MenuBoard[len][candi]);
        }
        return;
    }
    comb(str, pos+1, candi + str[pos]); // 알파벳 하나 선택 o
    comb(str, pos+1, candi);            // 알파벳 하나 선택 x
}
vector<string> solution(vector<string> orders, vector<int> course) {
    for (auto str: orders) {
        sort(str.begin(), str.end());
        comb(str, 0, "");
    }
    vector<string> answer;
    for (auto len: course) {
        for (auto item : MenuBoard[len]) {  // pair
            if (item.second >= 2 && item.second == MaxCnt[len]) {
                answer.push_back(item.first);
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<string> orders = {"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"};
    
    // 메뉴 갯수 2 or 3 or 4
    // 갯수가 같은 것이 여러개다 -> 모두 수용
    vector<int> course = {2, 3, 4}; 

    cout << "[";
    for(auto ans: solution(orders, course)) {
        cout << ans << " ";
    }
    cout << "]";

    return 0;
}