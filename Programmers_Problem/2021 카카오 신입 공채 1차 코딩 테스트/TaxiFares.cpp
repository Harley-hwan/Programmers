#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 30000000 // 200 * 100000 이상

int Fares[200][200];

void Floyd(int n) {     // n: 노드의 개수
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) 
            {
                // j->i->k 비용보다 j->k가 더 싸면?   Fares[j][k]는 원래 알고 있던 비용.
                // if (Fares[j][i] + Fares[i][k] < Fares[j][k])   
                //     Fares[j][k] = Fares[j][i] + Fares[i][k];
                Fares[j][k] = min(Fares[j][k], Fares[j][i] + Fares[i][k]);
            }
        }
     }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) Fares[i][j] = 0; //처음 0으로 초기화
            else        Fares[i][j] = MAX;
        }
    }

    for (auto edge : fares) 
    {
        // 시작점 문제에서 노드가 1, 2, 3, 4... 이런식이므로 -1해서 인덱스화해줌
        // {4, 1, 10} 이면 4->1 경로 비용 10인 건데 인덱스로는 3->1는 10 그리고 1->3도 10/
        Fares[edge[0] -1][edge[1]-1] = edge[2];      
        Fares[edge[1] -1][edge[0]-1] = edge[2];  //반대 방향
    }

    Floyd(n);

    // s--; a--; b--;  // 인덱스화.

    int answer = MAX;
    for (int i = 0; i < n; i++) {
        // adj[i][j]=MIN(adj[i][j], adj[i][k]+adj[k][j])
        answer = min(answer, Fares[s-1][i] + Fares[i][a-1] + Fares[i][b-1]);
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n = 6;
    int s = 4;
    int a = 6;
    int b = 2;

    vector<vector<int>> fares = {{4, 1, 10}, {3, 5, 24}, {5, 6, 2}, 
                                 {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, 
                                 {2, 4, 66}, {2, 3, 22}, {1, 6, 25}};
    

    cout << solution(n, s, a, b, fares);

    return 0;
}