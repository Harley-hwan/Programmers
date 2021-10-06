#include <iostream>
#include <vector>
using namespace std;

// 1 ~ n 까지 자연수 중 중복 없이 m개를 고른 수열

int n, m;
int arr[9];
bool visited[9];

void print() {
    for (int i = 0; i < m; i++) cout << arr[i] << " ";
    cout << "\n";
}

void dfs(int cnt) {
    while(cnt == m) {
        print();
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i] == true) continue;
        arr[cnt] = i;
        visited[i] = true;
        dfs(cnt + 1);
        visited[i] = false; 
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    
    dfs(0);

    return 0;
}