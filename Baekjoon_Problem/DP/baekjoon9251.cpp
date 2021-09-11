#include <iostream>
#include <string>
#include <algorithm>
#define endl '\n'
using namespace std;

int dp[1001][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s1, s2;
    cin >> s1 >> s2;

    for (int i = 0; i < s1.length(); i++) 
    { 
        for (int j = 0; j < s2.length(); j++) 
        {
            if (s1[i] == s2[j])
                dp[i+1][j+1] = dp[i][j] + 1;

            else 
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
        }
    }

    cout << dp[s1.length()][s2.length()] << endl;

    return 0;
}