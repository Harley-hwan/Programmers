#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 프로그래머스, 이민 (이진 탐색)

long long BSearch(int target, vector<int> times) {
    long long low = 0;  //나올 수 있는 가장 작은 수
    long long high = times[times.size() - 1];
    long long mid;
    high *= target;     // 나올 수 있는 가장 큰 수
    
    while(low <= high) {
        long long count = 0;
        mid = (low + high) / 2;
        for (int i = 0; i < times.size(); i++) {
            count += mid / times[i];
        }

        if (count == target)
            return mid;
        else if (count > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    //return mid;
}

long long solution(int n, vector<int> times) {
    long long answer = 0;

    sort(times.begin(), times.end());
    answer = BSearch(n, times);
    return answer;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n = 7; //cin >> n;
    //vector<int> times = {7, 10};
    vector<int> times = {8, 12};
    cout << solution(n, times) << "\n";
    return 0;
}