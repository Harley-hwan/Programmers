#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool sosu(int num) {
	if (num < 2) return false;
	int a = (int) sqrt(num);
	for (int i = 2; i <= a; i++) if (num % i == 0) return false;
	return true;
}

int solution(vector<int> nums) {
    int answer = 0;
    int n;
    for(int i = 0; i < nums.size()-2; i++) {
        for (int j = i+1; j < nums.size()-1; j++) {
            for (int k = j+1; k < nums.size(); k++) {
                n = nums[i] + nums[j] + nums[k];
                if (sosu(n)) answer++;
            }
        }
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<int> nums = { 1, 2, 3, 4 };

    cout << solution(nums) << "\n";

    return 0;
}