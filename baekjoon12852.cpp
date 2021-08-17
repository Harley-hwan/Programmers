#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000001

using namespace std;

// 백준 12852번: 1로 만들기 2
// X % 3 == 0  -> /3
// X % 2 == 0  -> /2
// -1

int dp[MAX];     //연산을 하는 횟수의 최솟값
int before[MAX]; // i로 오기 전에 어느 곳에 있었는지 저장

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    
    for (int i = 1; i <= N; i++) {
        dp[i] = i;
    }

    for (int i = 2; i <= N; i++) {
        if (i * 3 <= MAX) {
            if (dp[i * 3] == 0) {
                dp[i * 3] = min(dp[i * 3], (dp[i] + 1));
                before[i * 3] = i;
            }
        }

        if (i * 2 <= MAX) {
            if (dp[i * 2] == 0) {
                dp[i * 2] = min(dp[i * 2], (dp[i] + 1));
                before[i * 2] = i;
            }
        }

        if (i + 1 <= MAX) {
            if (dp[i + 1] == 0) {
                dp[i + 1] = min(dp[i + 1], (dp[i] + 1));
                before[i + 1] = i;
            }
        }
    }
    
    cout << dp[N] << "\n";

    while(1) {
        if (N == 1) {
            cout << N << " ";
            break;
        }

        cout << N << " ";
        N = before[N];
    }

    return 0;
}