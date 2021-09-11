#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
#define INF 987654321

int N, MinCnt;
vector<int> Weak;
vector<int> Dist;

void solve(int cnt, int pos, int visited) { // 친구 수, 시작위치, 방문여부
    if (cnt > Dist.size()) return; 
    if (cnt >= MinCnt) return;

    for (int i = 0; i < Weak.size(); i++) {
        int nextPos = (pos + i) % Weak.size();
        int diff = Weak[nextPos] - Weak[pos];
        if (nextPos < pos)
            diff += N;
        
        if (diff > Dist[Dist.size()-cnt])   // 못하는 경우
            break;

        visited |= 1 << nextPos;
    }

    if (visited == (1 << Weak.size()) - 1) { // 모든 비트가 1로 켜졌으면
        // MinCnt = min(MinCnt, cnt);
        MinCnt = cnt;
        return;
    }

    for (int i = 0; i < Weak.size(); i++) {
        if (visited & (1 << i)) continue;   // 이미 방문 스킵

        solve(cnt + 1, i, visited);
    }
}

int solution(int n, vector<int> weak, vector<int> dist) {
   
    sort(dist.begin(), dist.end());
    N = n;
    Weak = weak;
    Dist = dist;
    MinCnt = INF;

    for (int i = 0; i < Weak.size(); i++) {
        solve(1, i, 0);
    }
    if (MinCnt == INF) return -1;

    return MinCnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n = 12;
    vector<int> weak = {1, 5, 6, 10};
    vector<int> dist = {1, 2, 3, 4};

    cout << solution(n, weak, dist) << "\n";


    return 0;
}