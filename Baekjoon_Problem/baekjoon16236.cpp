#include <iostream>
#include <queue>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <algorithm>

using namespace std;

// 백준 16236번: 아기 상어

int N;
int board[21][21];

int dx[] = {0, -1, 1, 0};
int dy[] = {-1, 0, 0, 1};

struct Fish {
    int x, y, dist;
    
    // 연산자 오버로딩 (queue 정렬기준)
    bool operator<(const Fish &b) const
    {     
        if (dist == b.dist) 
        {
            if (y == b.y)   return x > b.x;
            return y > b.y;
        }
        return dist > b.dist;   
        // 나의 dist가 상대 dist보다 크면 우선순위 큐에서 swap
    }
};
queue<Fish> shark;

int GetMAX() {
    int time = 0, eat = 0, size = 2;

    while(1) 
    {
        priority_queue<Fish> feed;
        vector <vector<bool>> visit(N, vector<bool>(N));

        while(!shark.empty())
        {
            Fish cur = shark.front();
            shark.pop();

            for (int i = 0; i < 4; i++)
            {
                int ny = cur.y + dy[i], nx = cur.x + dx[i];
                if (ny < 0 || nx <0 || ny >= N || nx >= N)  continue;
                if (visit[ny][nx] || board[ny][nx] > size)  continue;

                visit[ny][nx] = 1;
                shark.push({ny, nx, cur.dist + 1});
                if (board[ny][nx] < size && board[ny][nx] != 0)
                    feed.push({ny, nx, cur.dist + 1});
            }
        }

        if (feed.empty())   break;  // feed가 비어있으면 break

        Fish sel = feed.top();      // 먹이 먹기
        int feedY = sel.y, feedX = sel.x, feedSize = board[feedY][feedX];
        if (++eat == size) {
            eat = 0;
            size++;
        }

        board[feedY][feedX] = 0;    // 먹이 위치로 이동
        shark.push({feedY, feedX, 0});

        time += sel.dist;
    }

    return time;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // input
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 9) {
                board[i][j] == 0;
                shark.push({i, j, 0});
            }
        }
    }
    // output
    cout << GetMAX() << "\n";
    return 0;
}