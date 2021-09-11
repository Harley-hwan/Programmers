#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    int answer = -1;
    
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<int>> board = {{1,1,1},{1,1,1},{1,1,1}};
    vector<int> aloc = {1, 0};
    vector<int> bloc = {1, 2};

    cout << solution(board, aloc, bloc);
    return 0;
}