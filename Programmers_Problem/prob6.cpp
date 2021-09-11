#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 시간 초과

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = board.size() * board[0].size();
    
    for(int i = 0; i < skill.size(); i++) {
        //for (int j = 0; j < skill[i].size(); j++) {
        int type = skill[i][0];
        int x1 = skill[i][1];
        int y1 = skill[i][2];
        int x2 = skill[i][3];
        int y2 = skill[i][4];
        int degree = skill[i][5];
        bool pos = true;

        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) {
                if (type == 1) {
                    if (board[i][j] > 0) pos = true;
                    else    pos = false;
                    board[i][j] -= degree;                   
                    if(board[i][j] <= 0 && pos == true) {
                        answer--;
                        pos = false;
                    }
                    //cout << answer<<"\n";
                }  
                else {
                    if (board[i][j] > 0) pos = true;
                    else    pos = false;
                    board[i][j] += degree;
                    if(board[i][j] > 0 && pos == false) {
                        answer++;
                        pos = true;
                    }
                    //cout << answer<<"\n";
                }
            }
        }
    }
         
//    for (int i = 0; i < board.size(); i++) {
//        for (int j = 0; j < board[i].size(); j++) {
//            if(board[i][j] > 0) answer++;
//        }
//    }
    
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();

    vector<vector<int>> board = {{5,5,5,5,5},{5,5,5,5,5},{5,5,5,5,5},{5,5,5,5,5}};

    vector<vector<int>> skill = {{1,0,0,3,4,4},{1,2,0,2,3,2},{2,1,0,3,1,2},{1,0,1,3,3,1}};
    cout << solution(board, skill) << "\n";

    return 0;
}