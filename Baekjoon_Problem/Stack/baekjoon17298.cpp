#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, num;
    vector<int> v;
    stack<int> s;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num;
        v.push_back(num);
    }

    vector<int> res(v.size(), -1);

    for (int i = 0; i < v.size(); i++) {
        while (!s.empty() && v[s.top()] < v[i]) {
            res[s.top()] = v[i];
            s.pop();
        }
        s.push(i);
    }


    for (int x : res) cout << x << " ";

    return 0;
}




// -----------------------------------------------------
// 시간 초과남

// int A[1000001];
// int n; 
// int NGE(int x) {
//     int ret = A[x];
//     while(1) {
//         if (x==n) return -1;
//         if (ret < A[x+1]) return A[x+1];
//         x++;
//     }
//     return -1;
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);

//     cin>> n;

//     for (int i = 0; i < n; i++) 
//         cin >> A[i];
        
//     for (int i = 0; i < n; i++) 
//         cout << NGE(i) << " ";

//     return 0;
// }
