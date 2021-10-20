#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    string res = "";
    int answer = 0;
    int temp_count = 1;

    int len = s.size();
    int answer = len;

    for (int i = 1; i <= n; i++) {
        string res = "";
        string subs = s.substr(0, i);

        int count = 1;

        for (int j = 1; j <= len; j+=i) {
            if (subs == s.substr(j, i)) count++;
            else {
                if (count == 1) res += subs;
                else            res += (to_string(count) + subs);
                subs = s.substr(j, i);
                count = 1;
            }
        }
        if ((len % i) != 0) {
            res += s.substr((len / i) * i);
        }

        if (answer > res.size()) answer = res.size();
    }
    return answer;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s = "aabbaccc";

    cout << solution(s) << "\n";

    return 0;
}