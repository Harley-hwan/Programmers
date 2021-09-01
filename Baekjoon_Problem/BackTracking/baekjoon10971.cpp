#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 백준 10971번: 외판원 순회 2 (Traveling Slesman problem: TSP)
// 백트래킹, 브루트포스 알고리즘

int W[11][11];
int ret;
vector<int> permu;
int N;

bool calculation() {
    ret = 0;
    for (int i = 0; i < N; i++) {
        if ( W[permu[i]][permu[(i + 1) % N]] == 0 )
           return false;
        ret += W[permu[i]][permu[(i + 1) % N]];
        cout << "ret: " << ret <<"\n";
    }
    return true;
}

int main() {   
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> W[i][j];
        }
        //cout << "i: " << i << "\n";
        permu.push_back(i); // 1, 2, 3, 4
    }
    
    int answer = 2e9;
    do
    {
        answer = calculation() ? min(answer, ret) : answer;
        cout << "answer: " << answer << "\n";
    } while (next_permutation(permu.begin() + 1, permu.end())); //모든 순열
    // 1 2 3 1
    // 2 3 1 2
    // 3 1 2 3
    // 모두 같다. 즉, 맨 앞 하나가 어떤 값이던 간에 변화가 없다.
    // 그래서 하나를 제외하고 반복. (N+1)! 와 N!의 차이를 만듦.


    cout << answer << "\n";
 
    return 0;
}