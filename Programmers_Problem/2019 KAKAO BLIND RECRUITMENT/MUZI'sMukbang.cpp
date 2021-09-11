#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;     // 음식 순서 작은게 먼저
}

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    vector<pair<int, int>> foods;   // { 먹는 시간, 먹는 순서(음식 번호) }
    
    int SIZE = food_times.size();
    for (int i = 0; i < SIZE; i++) {
        foods.push_back(make_pair(food_times.at(i), i+1));
    }
    sort(foods.begin(), foods.end());

    int pre = 0;    // 이전 시간

    for (vector<pair<int, int>>::iterator it = foods.begin(); it != foods.end(); it++, SIZE--) {   // 남은음식--
        long long spendT = (long long)(it->first - pre) * SIZE;
        if (spendT == 0) continue;
        if (spendT <= k) {
            k -= spendT;
            pre = it->first;    // 지금 시간으로 업데이트
        }
        else {
            k %= SIZE;  // 다 빼고 남은 것에서 사이즈를 나눈 나머지
            sort (it, foods.end(), comp);
            return (it+k)->second;
        }
    }

    return -1;
}