#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 백준 1517번: 버블 소트

long long res=0;

// merge sort, 정렬 도중 위치가 바뀌는 경우 swap되는 수 사이의 거리를 센다.
// 이 때 이 거리는 버블 정렬 할 때 이동횟수를 의미
void merge(vector<int> &v, int start, int end) {
    int mid = (start + end) / 2;
    int left = start;
    int right = mid + 1;
    vector<int> tmp;

    if (start == end) return;

    merge(v, start, mid);
    merge(v, mid + 1, end);

    while(left <= mid && right <= end) {
        if (v[left] <= v[right]) 
            tmp.push_back(v[left++]);
        else {
            tmp.push_back(v[right++]);
            res += (mid + 1- left);
        }
    }
    while(left <= mid) tmp.push_back(v[left++]);
    while(right <= end) tmp.push_back(v[right++]);

    for (int i = start, j = 0; i <= end; i++, j++) {
        v[i] = tmp[j];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N; cin >> N;
    vector<int> v(N);// = {3, 2, 1};
    //v.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    merge(v, 0, N-1);
    cout << res << "\n";
    
    return 0;
}