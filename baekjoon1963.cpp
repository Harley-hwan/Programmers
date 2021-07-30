#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

// 백준 1963번: 소수 경로 (bfs)

using namespace std;

#define MAX 10000

// int IsPrime(int number) {
//     int lcnt = 0;
//     for (lcnt = 2; lcnt < sqrt(number); lcnt++) {
//         if ((number % lcnt) == 0) return 0;
//     }
//     return 1;
// }

bool primes[MAX];
bool visited[MAX];

void IsPrime() {
    primes[1] = true;

    for (int i = 2; i < sqrt(MAX); i++) {
        if (primes[i]) continue;

        for (int j = i * 2; j < MAX; j += i)
            if(!primes[j])  primes[j] = true;

    }
}

int bfs(int num1, int num2) {
    queue<pair<int, int>> q;
    q.push({ num1, 0 });
    visited[num1] = true;

    while(!q.empty()) {
        int here = q.front().first;
        int move = q.front().second;
        q.pop();

        if (here == num2) return move;

        for (int i = 1; i <= 4; i++) {
            int there;
            switch(i) {
            case 1:     // 1000의 자리
                for (int j = 1; j <= 9; j++) {
                    there = (j * 1000) + (here % 1000);
                    if (!visited[there] && !primes[there]) {
                        visited[there] = true;
                        q.push({ there, move + 1 });
                    }
                }
                break;
            case 2:     // 100의 자리
                for (int j = 0; j <= 9; j++) {
                    there = (here / 1000 * 1000) + ( j * 100) + (here % 100);
                    if (!visited[there] && !primes[there]) {
                        visited[there] = true;
                        q.push({ there, move + 1 });
                    }
                }
                break;
            case 3:     // 10의 자리
                for (int j = 0; j <= 9; j++) {
                    there = (here / 100 * 100) + (j * 10) + (here % 10);
                    if (!visited[there] && !primes[there]) {
                        visited[there] = true;
                        q.push({ there, move + 1 });
                    }
                }
                break;
            case 4:     // 1의 자리
                for (int j = 0; j <= 9; j++) {
                    there = (here / 10 * 10) + j;
                    if (!visited[there] && !primes[there]) {
                        visited[there] = true;
                        q.push({ there, move + 1 });
                    }
                }
            }
        }
    }

    return -1;       
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    IsPrime();
    int T; cin >> T;
    for (int i = 0; i < T; i++) {
        memset(visited, false, sizeof(visited));
        int sosu1, sosu2;
        cin >> sosu1 >> sosu2;

        int res = bfs(sosu1, sosu2);

        if (res == -1)  cout << "Impossible" <<"\n";
        else            cout << res << "\n";
    }
    return 0;
}