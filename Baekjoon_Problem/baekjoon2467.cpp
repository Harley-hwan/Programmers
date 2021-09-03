#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 백준 2467번: 용액

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N; cin >> N;

    long long v[N];

    for (int i = 0; i < N; i++)  {cin >> v[i];}
    
    // sort(v.begin(), v.end());    // 이미 오름차순

    // 1 2 3 4 5
    // 1 + 5 > 0 이면, 0과 가까워야하므로 2 + 5가 아닌 1 + 4를 해봐야함.

    int front = 0;
    int end = N-1;
    int index1, index2;
    long long sum = 9999999999;
    while(front < end) {
        if (sum >= abs(v[front] + v[end])) {
            sum = abs(v[front] + v[end]);
            index1 = front;
            index2 = end;
        }

        if ((v[front] + v[end]) > 0)  end--;
        else                          front++;
        
    }
    //cout << sum << "\n";
    cout << v[index1] << " " << v[index2] << "\n";
    
    return 0;
}