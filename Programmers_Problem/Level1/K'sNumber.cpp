#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;
    
    for (int j = 0; j < commands.size(); j++) {
        for(int i = commands[j][0]-1; i <= commands[j][1]-1; i++) {
            temp.push_back(array[i]);
        }
        sort(temp.begin(), temp.end());
        
        answer.push_back(temp[commands[j][2]-1]);  
        temp.clear();
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> array = {1, 5, 2, 6, 3, 7, 4};
    vector<vector<int>> commands = { {2, 5, 3}, {4, 4, 1}, {1, 7, 3} };

    for (auto a : solution(array, commands)) {
        cout << a << " ";
    }

    return 0;
}