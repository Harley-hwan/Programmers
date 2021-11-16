#include <iostream>
#include <vector>

using namespace std;

int Having[200001];

int solution(vector<int> nums) {
    int answer = 0;

    for (int i = 0; i < nums.size(); i++) {
        Having[nums[i]] = 1;
    }

    for (int i = 0; i < 10001; i++) {
        if (Having[i] == 1) {
            answer++;
        }
    }
    if (answer > nums.size() / 2) answer = nums.size() / 2;

    return answer;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //vector<int> nums = {3, 1, 2, 3};
    //vector<int> nums = {3, 3, 3, 2, 2, 4};
    vector<int> nums = {3, 3, 3, 2, 2, 2};

    cout << solution(nums) << "\n";
    return 0;
}