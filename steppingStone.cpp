#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// programmers problem : 징검다리 (이분탐색)

int BSearch(int distance, vector<int> rocks, int n) {
    int low = 0;
    int high = distance;
    int mid;
    
    vector<int> gap;    //바위들 사이 간격 저장 벡터
    int start = 0;
    for (int i = 0; i < rocks.size(); i++) {
        gap.push_back(rocks[i] - start);
        start = rocks[i];
    }
    gap.push_back(distance - start);
    int count, prev;
    while(low < high) { // low와 high가 같아질 때까지 이분탐색
        
        mid = (low + high + 1) / 2; // 바위들 사이의 최소 간격
        count = 0;  // 제거해야 하는 바위 수
        prev = 0;
        for (int i = 0; i < rocks.size(); i++) {
            if (mid <= gap[i] + prev) prev = 0;     // 이 간격이 가능한가?
            else {  // 징검다리 제거
                count++;
                prev += gap[i];
            }
        }
        
        if (count > n)  high = mid - 1; // n보다 count가 큰 경우는 불가능하므로
        else            low = mid;
    }
    return low;
}

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    sort(rocks.begin(), rocks.end());
    answer = BSearch(distance, rocks, n);


    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int distance = 25;
    vector<int> rocks = {2, 14, 11, 21, 17};
    int n = 2;

    cout << solution(distance, rocks, n) << "\n";
    return 0;
}