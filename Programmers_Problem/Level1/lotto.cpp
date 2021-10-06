#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    //sort(lottos.begin(), lottos.end());
    //sort(win_nums.begin(), win_nums.end());
    
    int count = 0;
    int zero_count = 0;
    for (int i = 0; i < lottos.size(); i++) {
        for (int j = 0; j < win_nums.size(); j++) {
            if (lottos[i] == 0) {
                zero_count++;
                break;
            }
            else {
                if (lottos[i] == win_nums[j]) {
                    count++;
                    break;
                }
            }
        }
    }
    
    if ((count+zero_count) < 2) {
        answer.push_back(6);
        answer.push_back(6);
    }
    else{
        answer.push_back(7-(count+zero_count));
        if (count < 2) {
            answer.push_back(6);
        }
        else {
            answer.push_back(7-count);
        }
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> lottos = {44, 1, 0, 0, 31, 25};
    vector<int> win_nums = {31, 10, 45, 1, 6, 19};
    cout << "[" << solution(lottos, win_nums)[0] << ", " << solution(lottos, win_nums)[1] << "]\n";

    return 0;
}