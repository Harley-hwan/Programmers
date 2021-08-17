#include <iostream>
#include <algorithm>

using namespace std;

// 백준 9658번: 돌 게임 4

int dp[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int DP[1010];
    
    int n;	cin >> n;
 
	DP[1] = 0;
	DP[2] = 1;
	DP[3] = 0;
	DP[4] = 1;
	
	for (int i = 5; i <= n; ++i) {
		if (min({ DP[i - 1], DP[i - 3], DP[i - 4] }) == 1)  DP[i] = 0;
		else                                                DP[i] = 1;
	}

    if (DP[n] ==1)   cout << "SK" <<"\n";
    else             cout << "CY" <<"\n";

    return 0;
}