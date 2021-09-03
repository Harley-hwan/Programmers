#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>

using namespace std;

// 백준 3020번: 개똥벌레
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, H;
    cin >> N >> H;

    int arr[H][N];

    memset(arr, 0, sizeof(arr));
    int num, index;

    for (int i = 0; i < N; i++) {
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
    int count;

    for (int i = 0; i < N; i++) {
        count = 0;
        for (int j = 0; j < H; j++) {
            if (arr[i][j] == 1) count++;
        }
        v.push_back(count);
    }
    sort(v.rbegin(), v.rend());
    
    int MIN_count;

    int MINN = v[0];
    for(int i = 0; i < H; i++) {

    }
    MIN_count = count(v.begin(), v.end(), 3);
    cout << MINN << " " << MIN_count << "\n";

    return 0;
}