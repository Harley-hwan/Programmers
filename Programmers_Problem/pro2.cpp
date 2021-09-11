#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

long long transform(int num, int n) {
    if ( n < 3 || n > 10) return 0;
    
    long res = 0;
    num *=n;
    for (int cnt = 1; ;num /= n, cnt *=10) {res += (num % n) * cnt; }
    
    return res;
}

bool isPrime(long long n) {
    if (n == 0 | n == 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int solve(int n) {
    
}

int solution(long long nn, int k) {
    int answer = 0;
    //int nn = transform(n, k);
    for (int i = 2; i <= nn; i++) {
        if(isPrime(nn)) answer++;
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n = 437674;
    int k = 3;
    //long long nn = transform(n, k);
    long long nn = 211020101011;
    cout << transform(n ,k) << "\n";
    cout << solution(nn, k) << "\n";

    return 0;
}