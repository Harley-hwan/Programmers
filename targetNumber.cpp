#include <iostream>
#include <vector>
#include <string>

using namespace std;

int answer = 0;

void dfs(vector<int> numbers, int target, int sum, int count)  {
    if (count == numbers.size()) {
        if (sum == target) answer++;
        return;
    }
    dfs(numbers, target, sum + numbers[count], count + 1);
    dfs(numbers, target, sum - numbers[count], count + 1);
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, target, 0, 0);
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    
    vector<int> numbers = {1, 1, 1, 1, 1};
    int target = 3;
    cout << solution(numbers, target) <<"\n";

    return 0;
}