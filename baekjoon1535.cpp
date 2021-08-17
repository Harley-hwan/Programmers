#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define max(a,b) a>b ? a:b;

int solution(int W, int wt[], int val[], int N)
{
    // making and initializing dp array
    int dp[W];
    memset(dp, 0, sizeof(dp));  // dp size만큼 다 0으로 set.
 
    for (int i = 0; i < N; i++) {
        for (int w = W; w > 0; w--) {
 
            if (wt[i] <= w)
                // finding the maximum value
                dp[w] = max(dp[w],
                            dp[w - wt[i]] + val[i]);
        }
    }
    return dp[W-1]; // returning the maximum value of solution
}
// int solution(int pos, int capacity) {
// 	if (pos == N) return 0;
	
// 	int ret = 0;
// 	if (items[pos][W] <= capacity) //지금 pos의 물건을 훔칠 수 있을때
// 		ret = solution(pos + 1, capacity - items[pos][W]) + items[pos][V];
//         //지금 pos의 물건을 훔치지 않을때와 ret 중에 큰 값
// 	ret = MAX(ret, solution(pos + 1, capacity)); 
// 	return ret;
// }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    
    int wt[201];
    int val[201];

    for (int i = 0; i < N; i++) {
        cin >> wt[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> val[i];
    }
    int W = 100;
    //int n = sizeof(val) / sizeof(val[0]);
    cout << solution(W, wt, val, N);
    return 0;

}