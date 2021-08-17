#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// 프로그래머스
// 코딩 테스트 연습 > 2018 KAKAO BLIND RECRUITMENT
// > [3차] 압축
// LZW(Lempel-Ziv-Welch) 압축 구현

//dictionary
//vector<string> dict;

// // Check if there is same alphabet in dictionary
// bool FindAlpha(string msg, string voca) {
//     for (int i = 0; i< voca.length(); i++) {
//         if (voca[i] != msg[i])  return false;
//         }
//     }
//     return true;
// }

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> word;  // 알파벳 대문자 + 인덱스
    
    vector<string> dict = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};

    int count = 1;      // 단어 나누는 위치
    int current_n = 27; // 사전 단어 개수

    for (int i = 0; i < 26; i++) word.insert(make_pair(dict[i], i+1));

    while(1) {  // 단어 압축
        string w = msg.substr(0, count);    // 현재 입력
        string c = msg.substr(count, 1);    // 다음 글자
        string wc = w + c;                  // 추가할 단어
        auto tmp_w = word.find(w);      // 반복자 (사전에서 찾기)
        auto tmp_c = word.find(c);
        auto tmp_wc = word.find(wc);

        if (tmp_w != word.end()) {
            if (tmp_wc != word.end()) {  //wc가 사전에 있으면 count++
                if (count < msg.size()) count++;
            }
            else {  //wc가 사전에 없으면 count = 1, msg에서 지운다.
                answer.push_back(tmp_w->second);    // index
                word.insert(make_pair(wc, current_n++));
                msg.erase(0, count);
                count = 1;
            }    
        }
        if (c == "\0") {    //c가 msg끝에 도달-> answer에 마지막 단어 인덱스 넣고 끝
            answer.push_back(tmp_w->second);
            break;
        }
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string msg = "KAKAO";
    solution(msg);
    
    return 0;
}