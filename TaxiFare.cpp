#include<iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n = 6;
    int s = 4;
    int a = 6;
    int b = 2;

    vector<vector<int>> fares = {{4, 1, 10}, {3, 5, 24}, {5, 6, 2}, 
                                 {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, 
                                 {2, 4, 66}, {2, 3, 22}, {1, 6, 25}};
    

    cout << solution(n, s, a, b, fares);

    return 0;
}