#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dp[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0 ;

    for (auto p : puddles) {
        dp[p.front()][p.back()] = -1;
    }

    // for (int i = 0; i < puddles.size(); i++) {
    //     dp[puddles[i][1]][puddles[i][0]] = -1;
    // }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 && j == 1) dp[i][j] = 1; // 출발 : 1
            else if (dp[i][j] != -1) {  // 웅덩이가 아닐 때
                int sum = 0;
                sum += (dp[i-1][j] != -1 ? dp[i-1][j] : 0); // 왼쪽 웅덩이 -> 왼쪽이랑 dp같음
                sum += (dp[i][j-1] != -1 ? dp[i][j-1] : 0); // 위쪽 웅덩이 -> 위쪽이랑 dp같음
                dp[i][j] = sum % 1000000007;
            }
        }
    }
    answer = dp[m][n];

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int m, n; 
    //cin >> m >> n;
    
    m = 4; n = 3;
    vector<vector<int>> puddles = {{2, 2}};

    cout << solution(m, n, puddles);
    return 0;
}