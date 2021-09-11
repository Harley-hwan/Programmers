#include <iostream>
#include <string>
#include <algorithm>

#define endl '\n'
using namespace std;

//  백준 9252번: LCS 2 (Longest Common Subsequence, 최장 공통 부분 수열)

int dp[1001][1001];
string lcs[1001][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s1, s2;
    cin >> s1 >> s2;

    for (int i = 0; i < s1.length(); i++) {

        for (int j = 0; j < s2.length(); j++) {

            if (s1[i] == s2[j]) {

                dp[i+1][j+1] = dp[i][j] + 1;
                lcs[i+1][j+1] += lcs[i][j] + s1[i];
            }
            else {

                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);

                if (lcs[i][j+1].length() > lcs[i+1][j].length())
                    lcs[i+1][j+1] = lcs[i][j+1];

                else
                    lcs[i+1][j+1] = lcs[i+1][j];
            }
        }
    }

    cout << dp[s1.length()][s2.length()] << endl;
    cout << lcs[s1.length()][s2.length()] << endl;

    return 0;
}