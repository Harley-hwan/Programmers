#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int before = 0;
    vector<int> v;

    for (int i = 0; i < moves.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            if (board[j][moves[i]-1] != 0) {
            
                if (before == board[j][moves[i]-1]) {
                    v.pop_back();

                    answer = answer + 2;
                    before = v.back();
                    board[j][moves[i]-1] = 0;
                    break;
                }
                v.push_back(board[j][moves[i]-1]);
                before = board[j][moves[i]-1];

                board[j][moves[i]-1] = 0;
                break;
            }
        }
    }
    return answer;
}
// 4
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<int>> board = { {0,0,0,0,0},
                                  {0,0,1,0,3},
                                  {0,2,5,0,1},
                                  {4,2,4,4,2},
                                  {3,5,1,3,1} };

    vector<int> moves = {1, 5, 3, 5, 1, 2, 1, 4};

    cout << solution(board, moves) << "\n";

    return 0;
}