#include <iostream>

using namespace  std;

// H * N 사다리 만들고
// A번 세로줄, A+1번 세로줄 사이에 B번 가로줄 연결하면 사다리 [A][B] 연결(1).
// recursion으로 가능한 사다리 생성
// 사다리에 가로줄을 만들때, 가로줄은 연속해서 만들지 x
// 현재 위치 (i, j), 사다리 연결 (1) -> (i, j+2)로 이동
// 현재 위치 (i ,j), 사다리 연결x(0) -> (i, j)에 가로줄 생성, i+2로 이동 후 재귀 함수 호출
// 가로줄 최대 3개
// 정답 나왓으면, 더 이상 재귀 x

// 사다리 하나 만들때마다 제대로 연결됐는지 확인
// 1~N 세로줄 모두 확인
// 현재 위치 (i, j)에 사다리가 연결 (1)-> 오른쪽(i, j+1)으로 꺾는다. 
// 현재 위치 (i, j)에 사다리가 연결x(0)-> 왼쪽(i, j-1)== 1 -> 왼쪽(i, j-1)으로 꺾는다.
// 현재 위치에서 사다리를 한 칸 내려간다. (i+1, j)
// 위 과정을 가로줄 H 까지 반복

int n, m, h, ans=4;
bool a[30][10];

bool ladder() {
    for (int i=0; i<n; i++) {
        int k=i;
        for (int j=0; j<h; j++) {
            if (a[j][k]) k += 1;
            else if (k > 0 && a[j][k-1]) k -= 1;
        }
        if (i != k) return false;
    }
    return true;    
}

void solve(int cnt, int x, int y) {
    if (ans <= cnt) return;
    if (ladder()) {
        if (ans > cnt) ans = cnt;
        return;
    }
    if (cnt == 3) return;
    for (int i=x; i<h; i++, y=0) {
        for (int j=y; j<n-1; j++) {
            if (a[i][j]) {
                j += 1;
            } else {
                a[i][j] = 1;
                solve(cnt+1, i, j+2);
                a[i][j] = 0;
            }
        }
    }
}

int main() {
    cin >> n >> m >> h;
    
    for (int i=0; i<m; i++) {
        int x, y;  
        cin >> x >> y;
        a[x-1][y-1] = 1;
    }
    solve(0, 0, 0);
    cout << ((ans < 4) ? ans : -1) << "\n";
    
    return 0;
}
