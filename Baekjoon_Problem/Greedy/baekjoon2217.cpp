#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;

    int w;

    for (int i = 0; i < n; i++) {
        cin >> w;
        pq.push(w);
    }

    long long ans, max = 0;
    for (int i = 0; i < pq.size(); i++) {
        ans = (n-i) * pq.top();
        max = (max < ans) ? max : ans;
        pq.pop();
    }

    cout << max << endl;


    return 0;
}