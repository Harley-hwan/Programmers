#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int one[5] = {1, 2, 3, 4, 5};
int two[8] = {2, 1, 2, 3, 2, 4, 2, 5};
int three[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};


vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int on = 0;
    int tw = 0;
    int th = 0;
    
    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == one[i % 5]) on++;
        if (answers[i] == two[i % 8]) tw++;
        if (answers[i] == three[i % 10]) th++;
    }
    if (on >= tw && on >= th) {
        answer.push_back(1);
    }
    if (tw >= on && tw >= th) {
        answer.push_back(2);
    }
    if (th >= on && th >= tw) {
        answer.push_back(3);
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> answers = {1, 2, 3, 4, 5};
    for (auto a: solution(answers)) {
        cout << a << " ";
    }
    return 0;
}