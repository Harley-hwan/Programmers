#include <iostream>
#include <vector>

using namespace  std;

int dp1[1000001] = {0, };
int dp2[1000001] = {0, };

int max(int a, int b) { if (a > b) return a; return b; }

int solution(vector<int> money) {
    int answer = 0;

    //첫번째 집 털기 -> 마지막 집 못텀(인접)
    dp1[0] = money[0];
    dp1[1] = money[0];
    for (int i = 2; i < money.size()-1; i++) {
        dp1[i] = max(dp1[i-1], dp1[i-2] + money[i]);
    }

    //두번째 집 털기 -> 마지막 집 털수 있음.
    dp2[1] = money[1];
    for (int i = 2; i <= money.size()-1; i++) {
        dp2[i] = max(dp2[i-1], dp2[i-2] + money[i]);
    }

    // dp1:마지막 집 안 털기 때문에 마지막 직전의 인덱스까지
    // dp2:마지막 집 털 수 있기 때문에 마지막 인덱스까지
    answer = max(dp1[money.size()-2], dp2[money.size()-1]);
    return answer;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<int> money = {1, 2, 3, 1};

    cout << solution(money);

    return 0;
}