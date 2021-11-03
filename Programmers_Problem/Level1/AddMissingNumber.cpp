#include <iostream>
#include <string>
#include <vector>

using namespace std;

int isvisited[10];

int solution(vector<int> numbers) {
    int answer = 0;
    for (auto n : numbers) {
        for (int i = 0; i < 10; i++) {
            if (n == i) {
                isvisited[i] = 1;
                break;
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        if (isvisited[i] != 1) {
            answer += i;
        }
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<int> numbers = {1, 2, 3, 4, 6, 7, 8, 0};

    cout << solution(numbers) << '\n';

    return 0;
}
