#include <iostream>
#include <string>
#include <vector>

using namespace std;

int Total(vector<int> v) {
    int res = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] != 0) {
            res += (v.size()-i);
        }
    }
    return res;
}

void makePossible(int n, vector<int> v) {
    int SIZE = v.size()-1-i;
    for (int i = 0; i < n; i++) {
        v.push_back(SIZE);
    }
}

//어피치가 라이언의 점수보다 크거나 같으면 어피치가 win

bool ApichWin(vector<int> v1, vector<int> v2) {
    if (Total(v1) >= Total(v2)) return true;
    return false;
}
vector<int> solution(int n, vector<int> info) {
    vector<int> answer;

    //for (int i = n; )
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n = 5;

    vector<int> info = {2, 1, 1, 1, 0, 0, 0, 0, 0, 0};

    //cout << solution(n, info) << "\n";
    cout << Total(info);
    return 0;
}
