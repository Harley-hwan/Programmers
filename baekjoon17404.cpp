#include <iostream>
#include <vector>
using namespace std;

// 백준 17404번: RGB거리 2

#define MAXX 999999
int dp[1001][3];
int cost[1001][3];

int min(int a, int b) { if (a > b) return b; return a;}

int solution(int N) {
    int answer = MAXX;

    // i : RGB (1번째 집의 색)
    for (int i = 0; i < 3; i++) {  
        // 1번집에 지정된 색 이외의 색은 MAXX로 지정해서 dp할때 선택안되도록.
        for (int j = 0; j < 3; j++) {
            if (j == i) dp[1][j] = cost[1][j];
            else dp[1][j] = MAXX;
        }

        // dp
        for (int j = 2; j <= N; j++) {
            dp[j][0] = cost[j][0] + min(dp[j-1][1], dp[j-1][2]);
            dp[j][1] = cost[j][1] + min(dp[j-1][0], dp[j-1][2]);
            dp[j][2] = cost[j][2] + min(dp[j-1][0], dp[j-1][1]);
        }

        // 1번, N번 집 색 안 겹치게
        for (int j = 0; j < 3; j++) {
            if (j == i) continue;
            else answer = min(answer, dp[N][j]);
        }
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

//    int cost[3][3] = {{26, 40, 83}, {49, 60, 57}, {13, 89, 99}};

    int N; cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];

    cout << solution(N) <<"\n";
    return 0;
}
