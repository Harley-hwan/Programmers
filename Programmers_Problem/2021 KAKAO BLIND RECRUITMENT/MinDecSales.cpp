#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 987654321

// Programmers
// 2021 KAKAO BLIND RECRUITMENT > 매출 하락 최소화

// (직원번호, 해당 직원의 하루평균 매출액)
vector<int> Sales;
vector<vector<int>> Child(300000);
int Cost[300000][2];

void traversal(int node) {
    Cost[node][0] = 0;
    Cost[node][1] = Sales[node];

    if (Child[node].empty()) return;

    int extraCost = INF;
    for (auto child : Child[node]) {
        traversal(child);
        if (Cost[child][0] < Cost[child][1]) {
            Cost[node][0] += Cost[child][0];
            Cost[node][1] += Cost[child][0];
            extraCost = min(extraCost, Cost[child][1] - Cost[child][0]);
        }
        else {
            Cost[node][0] += Cost[child][1];
            Cost[node][1] += Cost[child][1];
            extraCost = 0;
        }
    }
    Cost[node][0] += extraCost;
}

int solution(vector<int> sales, vector<vector<int>> links) {
    Sales = sales;
    for (auto link : links) {
        Child[link[0]-1].push_back(link[1]-1);
    }
    traversal(0);
    return min(Cost[0][0], Cost[0][1]);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<int> sales = {14, 17, 15, 18, 19, 14, 13, 16, 28, 17};
    vector<vector<int>> links = 
            { {10, 8}, {1, 9}, {9, 7}, {5, 4}, {1, 5}, {5, 10}, {10, 6}, {1, 3}, {10, 2} };
    
    cout << solution(sales, links) << "\n";

    return 0;
}