#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define endl endl

using namespace std;

//  백준 2108번: 통계학 (정렬, 구현)


// 1. 산술평균: 평균
// 2. 중앙값:   증가하는 순서로 나열했을 때 그 중앙에 위치하는 값
// 3. 최빈값:   가장 많이 나타나는 값, 여러 개->두번째로 작은 값
// 4. 범위:     최댓값 - 최솟값

bool compare(pair <int, int> p, pair <int, int> p2) {
    if (p.first == p2.first) return p.first < p2.first;
    return p.second > p2.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    int num;
    vector<int> v;
    vector<pair<int, int> > vfreq;

    for (int i = 0; i < n; i++) {
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());
    int sum = 0;
    int count = 1;
    int freq = 1;

    for (int i = 0; i < n; i++) sum += v[i];
    //cout << endl;
    cout << round(float(sum) / n) << endl;           // 평균

    cout << v[n/2] << endl;                 // 중앙값


    for (int i = 0; i < v.size()-1; i++) {
        while(1) {
            if (v[i] != v[i+1]) break;
            count++;
            i++;
        }
        vfreq.push_back(make_pair(v[i], count));
        count = 1;
    }
    vfreq.push_back(make_pair(v[v.size()-1], count));

    sort(vfreq.begin(), vfreq.end(), compare);

    // cout << "--" <<endl;
    // for (auto vv : vfreq) {
    //     cout << vv.first << " " << vv.second << endl;
    // }
    // cout << "--" <<endl;
    if (n==1){
        cout << v[0] << endl;
        cout << int(v[n-1] - v[0]) << endl;    // 범위
    }
    else{
        if (vfreq[0].second == vfreq[1].second)   cout << vfreq[1].first << endl;     // 최빈값
        else                                      cout << vfreq[0].first << endl;
        cout << int(v[n-1] - v[0]) << endl;    // 범위
    }
    return 0;
}