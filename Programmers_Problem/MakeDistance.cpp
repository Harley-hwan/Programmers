#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

// 프로그래머스: 거리두기 확인하기(2021 카카오 채용연계형 인턴쉽)

struct Point {
    int row;
    int col;
    int dist;
};

int D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};   // 상하좌우

bool bfs(vector<string> place, int row, int col) {
    bool visited[5][5] = { false };

    queue<Point> q;
    visited[row][col] = true;   // 방문했다고 표기하고 시작
    q.push({row, col, 0});

    while(!q.empty()) {
        Point curr = q.front();
        q.pop();

        if (curr.dist > 2) continue;
        if (curr.dist != 0 && place[curr.row][curr.col] == 'P')
            return false;   //다른 사람 만난것. 바로 false 반환하고 끝.

        for (int i = 0; i < 4; i++) {
            int nr = curr.row + D[i][0], nc = curr.col + D[i][1];
            if (nr < 0 || nr > 4 || nc < 0 || nc > 4) continue; //5x5 밖.
            if (visited[nr][nc]) continue;   // 이미 가봤다.
            if (place[nr][nc] == 'X') continue;     //partition skip
            visited[nr][nc] = true;
            q.push({nr, nc, curr.dist + 1});
        }
    }

    return true;        // 만나는 사람이 없다.
}

bool check(vector<string> place) {
    for (int  r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            if (place[r][c] == 'P') {   // 사람이다 -> bfs로 확인
                if (bfs(place, r, c) == false) return false;
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for (auto place : places) {
        if (check(place))
            answer.push_back(1);    //잘 지켜졌다. -> 1
        else
            answer.push_back(0);    //안 지켜졌다. -> 0
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<vector<string>> places = {{"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"}, 
                    {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"}, 
                    {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"}, 
                    {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"}, 
                    {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}};
    cout << "[";    
    for(int i = 0; i < 5; i++) {
        if (i !=4 ) cout << solution(places)[i] << ", ";
        else        cout << solution(places)[i];
    }
    cout << "]";

    return 0;
}