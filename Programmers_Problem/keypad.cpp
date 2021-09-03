#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int lx = 3, ly = 0, rx = 3, ry = 2;
int nx, ny;     // 입력된 숫자의 좌표
int move_l, move_r;
string answer;

void rHand() {
    answer += 'R';
    rx = nx; ry = ny;
}

void lHand() {
    answer += 'L';
    lx = nx; ly = ny;
}

string solution(vector<int> numbers, string hand) {
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 0) {  // 숫자 0일 때
            nx = 3; ny = 1;
        }
        else {
            nx = (numbers[i] - 1) / 3;
            ny = (numbers[i] - 1) % 3;
        }

        if (numbers[i] % 3 == 1)                    lHand();
        else if (numbers[i] && numbers[i] % 3 == 0) rHand();
        else {
            move_l = abs(nx-lx) + abs(ny-ly);
            move_r = abs(nx-rx) + abs(ny-ry);

            if (move_l < move_r)        lHand();
            else if (move_l > move_r)   rHand();
            else {
                if (hand == "left") lHand();
                else                rHand();
            }
        }
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> v = {1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5};
    string hand = "right";

    cout << solution(v, hand) << "\n";

    return 0;
}