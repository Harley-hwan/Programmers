#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 프로그래머스: 2020 KAKO BLIND RECRUITMENT - 가사 검색

class Trie {
public:
    Trie() : child(), cnt(0) {} // 멤버 변수 0으로  초기화
    void Insert(string str) {
        Trie* cur = this;      // node들을 Link를 타고 이동. curent 시작

        for (char ch : str) {
            cur->cnt++;
            if (cur->child[ch - 'a'] == nullptr)    // 처음이다.
                cur->child[ch - 'a'] = new Trie();  // 새로운 거 하나 만들어줌.

            cur = cur->child[ch - 'a'];   // 문자에 해당하는 link를 타고 이동.
        }
        cur->cnt++;
    }

    int Search(string str) {    //Keword 해당하는 몇개인지
        Trie* cur = this;      // 현재
        for (char ch : str) {   // str의 첫번째 문자부터 하나, 하나...
            if (ch == '?')  return cur->cnt; // 마지막 ?로 끝남.

            cur = cur->child[ch - 'a'];   // 해당하는 link에 포인터로 이동.
            if (cur == nullptr)    return 0;
        }
        return cur->cnt;
    }
private:
    Trie* child[26];    // alphabet
    int cnt;            // 각각의 갯수
};

Trie TrieRoot[10000];

Trie ReTrieRoot[10000]; // Reverse해서 저장.

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;

    for (string str : words) {
        TrieRoot[str.length() - 1].Insert(str);
        
        reverse(str.begin(), str.end());    //reverse 뒤집기
        ReTrieRoot[str.length() - 1].Insert(str);
    }

    for (string str : queries) {
        if (str[0] != '?') {
            answer.push_back(TrieRoot[str.length() - 1].Search(str));
        } else {
            reverse(str.begin(), str.end());
            answer.push_back(ReTrieRoot[str.length() - 1].Search(str));
        }
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<string> words = {"frodo", "front", "frost", "frozen", "frame", "kakao"};

    vector<string> queries = {"fro??", "????o", "fr???", "fro???", "pro?"};
    cout << "[";
    for (auto v : solution(words, queries)) {
        cout << v << ", ";
    }
    cout << "]";
    return 0;
}