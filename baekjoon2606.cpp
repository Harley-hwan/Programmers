#include <iostream>
#include <queue>

using namespace std;
#define MAX 101

// 백준 2606번: 바이러스


int map[MAX][MAX];
int visited[MAX];
int N, count;

void dfs(int node) {
    visited[node] = 1;

    for (int i = 1; i <= N; i++) {
        // cout <<"node " << node << " - " << i << "\n";

        if (!visited[i] && map[node][i] == 1) {
            count++;
            dfs(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int com;
    cin >> N;
    cin >> com;    

    int num1, num2;

    for (int i = 0; i < com; i++) {
        cin >> num1 >> num2;
        map[num1][num2] = map[num2][num1] = 1;
    }

    dfs(1);
    cout << count << "\n";

    return 0;
}