#include <iostream>
#include <algorithm>

using namespace std;

long long arr[10001];
long long dp[10001];

// 백준 2156번: 포도주 시식

int main() {
    // dp[N] : arr[1]~ arr[N] 포도주 마셨을 때 최대 양
    // 0번 연속: dp[N-1]
    // 1번 연속: dp[N-2] + arr[N]
    // 2번 연속: dp[N-3] + arr[N-1] + arr[N]

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    dp[0] = 0;   
    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];

    for (int i = 3; i <= N; i++) {
        dp[i] = dp[i - 1];
        if (dp[i] < dp[i - 2] + arr[i]) {
            dp[i] = dp[i - 2] + arr[i];
        }
        if (dp[i] < dp[i - 3] + arr[i - 1] + arr[i]) {
            dp[i] = dp[i - 3] + arr[i - 1] + arr[i];
        }
    }

    cout << dp[N];

    return 0;
}
//     int flag;
//     int sum, maxx = 0;

//     for (int i = 0; i < v.size()-1; i++) {
//         for (int j = i + 1; j < v.size(); j++) {
//             sum = 0;
//             if (flag == 2) {
//                 flag = 0; 
//                 i++;
//             }
//             sum += v[i];
//             if (maxx > sum) maxx = sum;
//         }
//     }
//     return 0;
// }
