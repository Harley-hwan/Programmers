#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#define mod 1000000007
using namespace std;

// 백준 11505번: 구간 곱 구하기

long long arr[1000002];
long long *tree;

long long init(int node, int start, int end) {
    if (start == end) return tree[node] = arr[start];
    int mid = start + (end - start) / 2;
    return tree[node] = (init (2 * node, start, mid)
                        * init(2 * node + 1, mid + 1, end)) % mod;
}

long long update (int node, int start, int end, int index, long long val) {
    if (index > end || index < start) return tree[node];
    if (start == end) return tree[node] = val;
    int mid = start + (end - start) / 2;
    return tree[node] = (update(2*node, start, mid, index, val)
                        *update(2*node+1, mid+1, end, index, val)) % mod;
}

long long multi(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 1;
    if (left <= start && end <= right) return tree[node];
    int mid = start + (end -start) / 2;
    return (multi(2 * node, start, mid, left, right)
            * multi(2 * node + 1, mid + 1, end, left, right)) % mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n;
    int m, k; cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) { cin >> arr[i]; }

    long long a, b, c;
    long long start, end;
    int size = ceil(log2(n));
    tree = new long long[1 << (size + 1)];

    init(1, 1, n);
    for (int i = 0; i < m + k; i++) {
        cin >> a >> b >> c;
        if (a == 1) {   // b번째 수를 c로 바꿔라.
            arr[b] = c;
            update(1, 1, n, b, c);
        }
        
        else {          // b~c 구간의 곱.
            end = b > c ? b : c;
            start = b > c ? c : b;
            cout << multi(1, 1, n, start, end) << "\n";
        }
    }

    return 0;
}