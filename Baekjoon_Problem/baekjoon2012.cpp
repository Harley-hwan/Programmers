#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

// 백준 2012번: 등수 매기기

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<int> v;

    for (int i = 0; i < N; i++) {
        int num; cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    long sum = 0;

    for (int i = 0; i < v.size(); i++) {
        sum += abs(v[i] - (i + 1));
    }

    cout << sum << "\n";
    return 0;
}