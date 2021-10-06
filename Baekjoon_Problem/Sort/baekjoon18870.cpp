#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int> p1, const pair<int, int> p2)
{
    return p1.second < p2.second;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> x;
    vector<pair<int, int> > v;

    for (int i = 0; i < n; i++) {
        int X; cin >> X;
        v.push_back(make_pair(X,i));
    }

    sort(v.begin(), v.end());

    // for (auto a : v) {
    //     cout << a.first << " " << a.second << "\n";
    // }

    int cnt = 0;
    vector<pair<int, int> > order;

    order.push_back(make_pair(0, v[0].second));

    for (int i = 1; i < v.size(); i++) {
        if (v[i].first != v[i-1].first) {
            cnt++;
            order.push_back(make_pair(cnt, v[i].second));
            continue;
        }
        order.push_back(make_pair(cnt, v[i].second));
    }
    
    sort(order.begin(), order.end(), compare);

    for (auto a : order) {
        cout << a.first << " ";
    }


    return 0;
}