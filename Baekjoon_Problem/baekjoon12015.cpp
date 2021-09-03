#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 백준 12015번: 가장 긴 증가하는 부분 수열 2
#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;

    vector<int> v = {1000000};
    int num; 

    for (int i = 0; i < N; i++) {
        cin >> num;
        if (num > v.back()) v.push_back(num);
        else {
            int index = lower_bound(v.begin(), v.end(), num) - v.begin();
            v[index] = num;
        }

    }

    cout << v.size() << "\n";

    return 0;
}

// vector<int> v;

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     long long N, num;

//     cin >> N;
//     for (long long i = 0; i < N; i++) {
//         cin >> num;
//         v.push_back(num);
//     }
//     sort(v.begin(), v.end());
//     v.erase(unique(v.begin(), v.end()), v.end());

//     for (int i = 0; i < v.size(); i++) {
//         cout << v[i] << " ";
//     }
//     cout << "\n";
//     cout << v.size() << "\n";

//     return 0;
// }