#include <iostream>
#include <string>
#include <vector>
#define MAX 201

using namespace std;

int visited[MAX];

void dfs(int node, int n, vector<vector<int>> &computers) {
    visited[node] = true;
    for (int i = 0; i < computers[node].size(); i++) {
        if (i != node && !visited[i] && computers[node][i]) {
            dfs(i, n, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for (int i = 0; i < computers.size(); i++) {
        if (!visited[i]) {
            dfs(i, n, computers);
            answer++;
        }
    }
    dfs(0, n, computers);
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cout << solution(3, { {1, 1, 0}, {1, 1, 0}, {0, 0, 1} } ) << "\n";

    // cout << solution(3, { {1, 1, 0}, {1, 1, 1}, {0, 1, 1} } ) << "\n";

}