#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long BSearch(long long arr[], long long target) {
    long long low = 0;
    long long high = arr.length - 1;
    long long mid;

    while(low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

long long solution(int n, vector<int> times) {
    long long answer = 0;

    return answer;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    

    return 0;
}