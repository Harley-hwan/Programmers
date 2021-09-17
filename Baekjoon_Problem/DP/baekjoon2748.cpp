#include <iostream>
#define MAX 100
using namespace std;

long long fibonacci[MAX] = {0, 1,};

// 백준 2748: 피보나치 수 2

long long fibo(int n) {
    if (n==0 || n==1) return fibonacci[n];
    else if (fibonacci[n] == 0) fibonacci[n] = fibo(n-1) + fibo(n-2);
    return fibonacci[n];

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    cout << fibo(n) << "\n";;

    return 0;
}