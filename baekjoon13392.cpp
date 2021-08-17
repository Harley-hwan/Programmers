#include <iostream>
#include <cmath>
#include <string.h>
#include <algorithm>

using namespace std;

int main() {
	int dp[10005][10];
	memset(dp, 0, sizeof(dp));
	int a[10005], b[10005], n;
	cin >> n;
    int temp = n;
    int aa; cin >> aa;
    int bb; cin >> bb;
    // 3
    // 326
    // 446
    int i = 1;
    while(n--) {
        // cout << "n: " << n <<"\n";
        // cout << "i: " << i <<"\n";
        // cout<< "aa: " << aa<<"\n";
        a[i] = aa / pow(10, n);
        // cout<< "a[" << i << "]: " << a[i]<<"\n";
        // cout<< "aa: " << aa<<"\n";
        aa -= (a[i] * pow(10, n));

        // cout<< "bb: " << bb <<"\n";
        b[i]= bb / pow(10, n);
        // cout<< "b[" << i << "]: " << b[i]<<"\n";
        // cout<< "bb: " << bb<<"\n";
        bb -= (b[i] * pow(10, n));
        i++;
    }
    // cout << "get out\n";
    n = temp;
    // FOR(i, 1, n) { cout << a[i] << b[i] <<"\n"; }

	for (int i = 0; i <= 9; i++) dp[0][i] = i;
	for (int i = 0; i <= n; i++) {
        for(int j = 0; j < 10; j++) {
            int lcnt = (b[i] - j - a[i] + 20) % 10;
            int rcnt = 10 - lcnt;
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + rcnt);
            dp[i][(j + lcnt) % 10] = min(dp[i][(j + lcnt) % 10], dp[i - 1][j] + lcnt);
        }
	}
	int ans = 99999999;
	for (int i = 0; i < 10; i++) ans = min(ans, dp[n][i]);
	cout << ans << "\n";
	return 0;
}