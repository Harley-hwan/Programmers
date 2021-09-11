#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

// 백준 10775번: 공항 (그리디 알고리즘)

bool isEmpty(int i, vector<int> g, int planes[]) {
    while(1) {
        cout << "i: " << i << "\n";
        cout << "planes: " << planes[g[i]] << "\n";
        if (planes[g[i]] == 0) return true;
        i--;
        if(i==0) break;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int G, P;
    cin >> G;   // 게이트 수
    cin >> P;   // 비행기 수

    vector<int> g;  // 비행기가 도킹 원하는 자리
    bool arr[G];

    int num;
    for (int i = 0; i < P; i++) {
        cin >> num;
        g.push_back(num);
    }

    // sort(g.begin(), g.end(), greater<int>());

    int count = 0;
    int planes[g.size()];

    memset(planes, 0, g.size() *sizeof(int));    

    for (int i = 0; i < P; i++) {
        cout << "get in" << "\n";
        cout << isEmpty(i, g, planes) << "\n";
        if (isEmpty(i, g, planes)) {
            cout << 1<< "\n";
            planes[g[i]] = 1;
            G--; 
            count++;
        }
        break;
    }

    cout << count << "\n";

    return 0;
}