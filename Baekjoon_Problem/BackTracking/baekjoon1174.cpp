#include <iostream>
#include <vector>
#include <queue>

#define MAX 9876543210

using namespace std;

// 백준 1174번: 줄어드는 숫자 (벡트래킹, 브루트포스, 정렬)


// 줄어드는 가장 큰 수: 9,876,543,210 = 2^10-1   --> long
// 총 1023개

/*  bfs
    3 => 32  / 31  / 30
      => 321 / 320 
      => 3210
    1의 자리 숫자 보고 그 숫자보다 작은 숫자들을 뒤에 붙인다.
    따로 sort할 필요없도록.
    붙어주는 숫자가 0부터 시작해야함.
    632 => 6320, 6321, 6322 (왜냐하면 N번째 작은 숫자를 출력해야하니까)
*/


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;

    vector<long long> decrease;  // 줄어드는 숫자 저장
    queue<long long> q;

    for (int i = 0; i <= 9; i++) {
        decrease.push_back(i);
        q.push(i);
    }

    // bfs
    while (!q.empty()) {
        long long a = q.front();
        // cout << "a: " << q.front() << "\n";
        q.pop();

        // 0 ~ a의 일의 자리 숫자의 값 -1 까지 차례로 뒤에 붙임.
        for (int i = 0; i <= (a % 10 - 1); i++) {
            long long n = 10 * a + i;
            decrease.push_back(n);
            q.push(n);

        }
    }

    if (N > decrease.size()) {
        cout << -1 << "\n";
    }
    else {
        cout << decrease[N-1] << "\n";
    }

    return 0;
}