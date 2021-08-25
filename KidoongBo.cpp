#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

// 프로그래머스: 기둥과 보 설치(2020 KAKAKO BLIND RECRUITMENT)

bool Kidoong[102][102];  // 기둥 (있다: 1, 없다: 0)
bool Bo[102][102];       // 보

bool checkKidoong(int x, int y) {   // 기둥 설치 가능?

    // 바닥이거나, 기둥 위의 기둥 설치인 경우
    if (y == 0 || Kidoong[x][y-1]) 
        return true;
    
    // 왼쪽에 보가 설치 되있나? 혹은 해당 위치에 보가 설치 되있나?(보는 오른쪽으로 설치되므로)
    if (x > 0 && Bo[x-1][y] || Bo[x][y]) 
        return true;

    return false;   // 두 경우 다 아닌 경우 -> 설치 불가능.
}

bool checkBo(int x, int y) {        // 보 설치 가능?

    // x+1이 100을 넘어가면 안되는데, 그냥 102개로 늘려줌.
    // 아래에 기둥이 있는지 or 오른쪽에 기둥이 있는지(보는 오른쪽으로 설치되니까)
    if (Kidoong[x][y-1] || Kidoong[x+1][y-1])
        return true; 
    
    // 왼쪽 or 오른쪽에 보가 있는 경우
    if (x > 0 && Bo[x-1][y] && Bo[x+1][y])
        return true;

    return false;   // 두 경우 다 아닌 경우 -> 설치 불가능.
}

bool canDel(int x, int y) {

    // x 좌표 좌우 확인, x가 0보다 작아지면 안되니까 max 사용
    for (int i = max(x - 1, 0); i <= x + 1; i++) {  
        for (int j = y; j <= y + 1; j++) {  // y 좌표 위 확인 (아래 필요x)

            // 기둥을 이미 지우고 들어왔는데 기둥이 존재할 수 있나?
            // 존재하지만 존재할 수 없는 경우라고 하면? false
            if (Kidoong[i][j] && checkKidoong(i, j) == false)
            //if (checkKidoong(i, j) == false)
                return false;
            
            // 보 마찬가지
            if (Bo[i][j] && checkBo(i, j) == false)
            //if (checkBo(i, j) == false)
                return false;
        }
    }

    return true;    // 삭제해도 된다.
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    memset(Kidoong, 0, sizeof(Kidoong));
    memset(Bo, 0, sizeof(Bo));

    for (auto build: build_frame) {
        int x = build[0], y = build[1];         // (x, y) 좌표
        int what = build[2], how = build[3];    // 무엇을(기둥/보) 어떻게(삭제/설치)

        if (what == 0) {                    // 기둥 (what == 0)

            if (how == 1) {                 // 설치 (how ==1)
                if (checkKidoong(x, y))     // Kidoong (기둥) 설치 가능?
                    Kidoong[x][y] = true;   // 그러면 설치.
            }
            else {                          // 삭제 (how == 0)
                Kidoong[x][y] = false;      // Kidoong (기둥) 일단 삭제
                if (canDel(x, y) == false)  // 삭제 불가능?
                    Kidoong[x][y] = true;   // 그럼 다시 설치
            }
        }
        else {                              // 보 (what == 1)

            if (how == 1) {                 // 설치 (how == 1)
                if (checkBo(x, y))          // Bo (보) 설치 가능?
                    Bo[x][y] = true;        // 그러면 다시 설치

            }
            else {                          // 삭제 (how == 0)
                Bo[x][y] = false;           // Bo (보) 일단 삭제
                if (canDel(x, y) == false)  // 삭제 불가능?
                    Bo[x][y] = true;        // 그럼 다시 설치
            }
        }
    }

    for (int x = 0; x <= n; x++) {
        for (int y = 0; y <= n; y++) {
            if (Kidoong[x][y])
                answer.push_back({x, y, 0});    // 기둥이 있다.

            if (Bo[x][y])
                answer.push_back({x, y, 1});    // 보가 있다.
        }
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n = 5;
    vector<vector<int>> build_frame = {{1,0,0,1},{1,1,1,1},
                    {2,1,0,1},{2,2,1,1},{5,0,0,1},
                    {5,1,0,1},{4,2,1,1},{3,2,1,1}};

    vector<vector<int>> answer;
    cout << "[";
    for (auto build: solution(n, build_frame)) {
        cout << "[" << build[0] <<"," << build[1] << "," << build[2] << "],";
    }
    cout << "]" << "\n";
    return 0;
}