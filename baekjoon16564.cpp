#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 백준 16564번: 히오스 프로그래머

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int answer, X;
    int N, K; 
    cin >> N >> K;
    
    vector <int> v;
    int sum = 0;

    for (int i = 0; i < N; i++) {
        cin >> X;
        sum += X;
        v.push_back(X);
    }
    sort(v.begin(), v.end());
    int n_Same, gap;
    while(1) {
        n_Same = upper_bound(v.begin(), v.end(), v[0]) - v.begin();

        if (n_Same == N) {
            answer = v[0] + K / n_Same;
            break;
        }

        gap = v[n_Same] - v[0];

        if (gap * n_Same <= K) v[0] += gap;
        else {
            answer = v[0] + K /n_Same;
            break;
        }
        K -= gap * n_Same;
    }

    cout << answer << "\n";

    return 0;
}