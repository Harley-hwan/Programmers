#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

int N, K;

int bfs(string s) {
    queue<pair<string, int>> q;
    q.push({ s, 0 });
    map<string, bool> visited;
    string target = s;
    sort(target.begin(), target.end()); //오름차순

    while (!q.empty()) {
        string cur = q.front().first;
        int count = q.front().second;
        q.pop();

        if (cur == target)  return count;

        if (!visited.count(cur)) {
            visited[cur] = true;

            for (int j = 0; j <= N - K; j++) {
                string tmp = cur.substr(j, K);
                reverse(tmp.begin(), tmp.end());

                q.push({ cur.substr(0, j) + tmp + cur.substr(j + K, cur.size()), count + 1 });
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
// 3 3
// 3 2 1
    cin >> N >> K;

    string s;

    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;

        s+= c;
    }

    cout << bfs(s) << "\n";
    return 0;
}
