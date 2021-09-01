#include <iostream>
#include <vector>
#include <algorithm>

#define INF 999999999

using namespace std;

// 프로그래머스 문제: GPS (2017 카카오코드 본선)

// long long init(vector<long long> &a, vector<long long> &tree, int node, int start, int end) {
//     if (start == end) {
//         return tree[node] = a[start];
//     } else {
//         return tree[node] = init(a, tree, node*2, start, (start+end)/2) + init(a, tree, node*2+1, (start+end)/2+1, end);
//     }
// }

// void update(vector<long long> &tree, int node, int start, int end, int index, long long diff) {
//     if (index < start || index > end) return;
//     tree[node] = tree[node] + diff;
//     if (start != end) {
//         update(tree,node*2, start, (start+end)/2, index, diff);
//         update(tree,node*2+1, (start+end)/2+1, end, index, diff);
//     }
// }

// long long sum(vector<long long> &tree, int node, int start, int end, int left, int right) {
//     if (left > end || right < start) {
//         return 0;
//     }
//     if (left <= start && end <= right) {
//         return tree[node];
//     }
//     return sum(tree, node*2, start, (start+end)/2, left, right) + sum(tree, node*2+1, (start+end)/2+1, end, left, right);
// }

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    int answer = 0;
    // root : 인접 list
    // 각 지점에 대응. 지점마다 자신과 인접한 지점들을 추가한다.
    // root[2] = [3,4]  2지점에서 3, 4 지점이 연결되어 있다.
    
    vector<vector<int>> root(n+1);

    for (int i = 0; i < edge_list.size(); i++) {
        int n1 = edge_list[i][0];
        int n2 = edge_list[i][1];
        root[n1].push_back(n2);
        root[n2].push_back(n1);
    }

    vector<vector<int>> dp(k, vector<int>(n + 1, INF));
    dp[0][gps_log[0]] = 0;  // 시작점   (i == 0)
    for (int i = 1; i < k; i++) {       
        for (int j = 1; j <= n; j++) {  
            // 가장 최소 변경 횟수
            // 1초 전에 j에 있었던 경우 (안 움직인 경우)
            int MINN = dp[i - 1][j];

            // j 와 인접한 지점에서 온 경우
            for (int l = 0; l < root[j].size(); l++) 
                MINN = min(dp[i - 1][root[j][l]], MINN);

            if (gps_log[i] != j) {
                dp[i][j] = MINN + 1;    // 변경이 필요하면 + 1
            }

            else    
                dp[i][j] = MINN;        // 유지
        }
    }

    answer = dp[k - 1][gps_log[k - 1]]; //gps_log[k-1] : 마지막 시간대에서의 최소 변경 횟수
    if (answer >= INF) answer--;        //dp[k-1][gps_log[k-1]] 가 INF보다 크면 변경 불가능

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    n = 7; 
    m = 10; 
    vector<vector<int>> edge_list = {{1, 2}, {1, 3}, {2, 3}, {2, 4}, {3, 4}, {3, 5}, {4, 6}, {5, 6}, {5, 7}, {6, 7}};
    k = 6;
    vector<int> gps_log = {{1, 2, 3, 3, 6, 7}};

    cout << solution(n, m, edge_list, k, gps_log) << "\n";
    return 0;
}