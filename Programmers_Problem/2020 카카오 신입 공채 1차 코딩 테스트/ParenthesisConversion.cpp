#include <iostream>
#include <string>
#include <stack>

using namespace std;

// 프로그래머스 문제 (카카오 코딩 테스트): 괄호 변환

bool Check(string str, int* pos) {
    bool ret = true;
    int open = 0, close = 0;    // 열린 괄호, 닫힌 괄호
    stack<char> s;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') {
            open++;         // 열린 괄호 카운팅
            s.push('(');    // 짝이 맞는지 확인하기 위해
        }
        else {
            close++;
            if (s.empty())  ret = false; // 짝이 안 맞는 경우: ')'를 넣어야하는데 '('가 없다.
            else            s.pop();     // '(' 를 지운다.
        }
        if (open == close) {  
            *pos = i + 1;     // 짤리는 위치. 길이로도 사용.
            return ret;
        }
    }

    // 문자열 p를 이루는 '(' 와 ')' 의 개수는 항상 같습니다. 그래서 여긴 안옴.
    //return true;    // 여기까지 오진 않을듯 
}

string solution(string p) {
    if (p.empty()) return p;                    // 1. 빈 문자열이면 빈 문자열 return

    int pos;
    bool check = Check(p, &pos);
    string u = p.substr(0, pos);                // 2. 문자열을 u, v로 분리
    string v = p.substr(pos, p.length()-pos);

    if (check) {                                // 3. u가 올바른 괄호 문자열이면, 
        return u + solution(v);                 // v를 1단계부터 다시 수행.
    }

    // else {
    // 아니라면
    string answer = "(" + solution(v) + ")";    // 4-1 , 4-2, 4-3
    for (int i = 1; i < u.length() - 1; i++){   // 4-4. 첫번째와 마지막 문자 제거
        if (u[i] == '(')
            answer += ")";  // 괄호 뒤집기
        else
            answer += "(";  // 괄호 뒤집기
    }    
    
    return answer;                              // 4-5. 문자 반환.
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string p = "(()())()";

    cout << solution(p) << "\n";

    return 0;
}