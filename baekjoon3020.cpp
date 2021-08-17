#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
// 백준 3020번: 개똥벌레
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll N, H;
    cin >> N >> H;

    ll arr[H][N];

    memset(arr, 0, sizeof(arr));
    ll num, index;

    for (ll i = 0; i < N; i++) {
        if (i % 2 == 0) {    
            cin >> num;
            index = H-1;
            while (num--) {
                arr[index][i] = 1;
                index--;
            }
        }
        else {
            cin >> num;
            index = 0;
            while (num--) {
                arr[index][i] = 1;
                index++;
            }
        }
    }
    ll count;
    for (ll i = 0; i < H; i++) {
        count = 0;
        for (ll j = 0; j < N; j++) {
            if (arr[i][j] == 1) count++;
        }
        v.push_back(count);
    }
    sort(v.begin(), v.end());

    ll MINN = v[0];
    ll MINN_count = 0;
    for(ll i = 0; i < v.size(); i++) {

        if(MINN == v[i]) MINN_count++;
    }
    //int MIN_count = count(v.begin(), v.end(), MINN);
    cout << MINN << " " << MINN_count << "\n";

    return 0;
}