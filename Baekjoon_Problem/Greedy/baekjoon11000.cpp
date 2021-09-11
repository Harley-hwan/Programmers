#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <queue>

using namespace std;

// 백준 11000번: 강의실 배정 (그리디 알고리즘)
vector<pair<int, int> > arr;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;

    priority_queue<int, vector<int>, greater<int>> classsR;
    vector<pair<int, int> > classs(N);
    
    // int from, to;
    
    for (int i = 0; i < N; i++) {
        cin >> classs[i].first >> classs[i].second;
    }
    
    sort (classs.begin(), classs.end()); // 정렬
    //for(auto i:classs) cout << i.first << i.second << "\n";

    classsR.push(classs[0].second);      // 시작부분을 우선순위 큐(pq)에 넣어줍니다.

    for (int i = 1; i < N; i++) {
        // pq의 값 가장 빨리 끝나는 강의실에 넣을 수 있으면 
        // 현재 시작위치를 넣을 수 있으면 그 pq를 갱신.
        // cout << "----" << "\n";
        // cout << classsR.top() << classs[i].first << "\n";
        if (classsR.top() <= classs[i].first){ 
            classsR.pop();
            classsR.push(classs[i].second);
        }

        // 만약 넣지 못한다면 pq를 하나 더 만들어줌.
        else {
            classsR.push(classs[i].second);
        }
    }
    
    cout << classsR.size() << "\n";

    return 0;
}

// ---------------------------------------------------------------

// int findIndex(int posem) {

//     for (auto i = 0; i < arr.size(); ++i) {
//         if (arr[i].first == posem)
//             return i;
//     }

//     return -1;
// }

// int main() {
//     //ios_base::sync_wposh_stdio(false);
//     cin.tie(0); cout.tie(0);

//     int N; cin >> N;
    
//     // arr[200010];
//     int from, to;
//     int maxx = 0;

//     for (int i = 0; i < N; i++) {
//         cin >> from >> to;
        
//         for (int j = from; j < to; j++) {
//             auto pos = findIndex(j);
//             //auto pos = find(arr.begin().second(), arr.end().second(), j);
//             if (pos != -1) {
//                 arr[pos].second++;
//                 if (arr[pos].second >= maxx) maxx = arr[pos].second;
//             }
//             else {
//                 arr.push_back(make_pair(j, 1));
//             }            
//         }
//     }
//     cout << maxx << "\n";

//     return 0;
// }

// ---------------------------------------------------------------

//     int N; cin >> N;
//     pair<int, int> v;
//     int arr[200010] = {0, };

//     int s,t ;
//     v.push_back({0,0});
//     for (int i = 0 ; i < N; i++) {
//         cin >> s >> t;
//         v.push_back(make_pair(s, t));
//     }
//     int from, to;
//     int maxx = 0;
//     for (int i = 1; i < N; i++) {
//         from = v[i].first;
//         to = v[i].second;
//         for (int j = from; j < to; j++) {
//             arr[j]++;
//             if (arr[j] >= maxx) maxx = arr[j];
//         }
//     }
//     cout << maxx << "\n";

//     return 0;
// } 