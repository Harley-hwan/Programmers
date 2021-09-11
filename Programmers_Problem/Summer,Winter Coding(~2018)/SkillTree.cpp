#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// int dp[30][30];
// string str[30];

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    for (int k = 0; k < skill_trees.size(); k++) {
        //vector<int> temp;
        string str;
        for (int i = 0; i < skill_trees[k].length(); i++) {
            for (int j = 0; j < skill.length(); j++) {
                if (skill[j] == skill_trees[k][i]) {
                    //temp.push_back(skill_trees[k][i]);
                    str += skill_trees[k][i];
                }
            }
        }
        //for (auto y: temp) cout << y << " ";
        bool ans = true;

        for (int i = 0; i < str.size(); i++) {
            if (str[i] != skill[i]) {
                ans = false;
                break;
            }
        }
        if (ans) answer++;

    }   

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string skill = "CBD";
    vector<string >skill_trees = {"BACDE", "CBADF", "AECB", "BDA"};

    cout << solution(skill, skill_trees) << "\n";
    return 0;
}