#include <iostream>

using namespace std;

int arr[100001];

bool isEven(int n) {
    if (n % 2) return false;
    return true;
}

bool isOdd(int n) {
    if (n % 2) return true;
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    int M; cin >> M;
    int a, b, c, count;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        count = 0;
        if (a == 1) arr[b] = c;
        if (a == 2) {
            for (int j = b; j <= c; j++) {
                if (isEven(arr[j])) count++;
            }
            cout << count << "\n";
        }
        if (a == 3) {
            for (int j = b; j <= c; j++) {
                if (isOdd(arr[j])) count++;
            }
            cout << count << "\n";
        }
    }

    return 0;
}