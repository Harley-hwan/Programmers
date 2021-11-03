#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> map;
    
    for (string name: participant) map[name]++;
    for (string name: completion) map[name]--;
    
    for (auto pair: map) 
        if (pair.second > 0)    return pair.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<string> participant = {"leo", "kiki", "eden"};
    vector<string> completion = {"eden", "kiki"};

    cout << solution(participant, completion) << "\n";

    return 0;
}