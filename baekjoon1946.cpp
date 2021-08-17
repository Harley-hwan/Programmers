#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v;

// 서류성적 기준으로 오름차순
bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int solution(vector<pair<int, int>> v) {
    sort(v.begin(), v.end(), cmp);

    // 서류 성적 1등 -> 무조건 채용
    int answer = 1;
    int cutline = v[0].second;  // 1등의 면접접수를 cutline
    
    // 서류성적 1등 빼고 나머지 지원자들 중 서류성적 1등의 면접정수보다 더 높은 사람 나오면
    // cutline을 그 사람 등수로 바꾼다.
    for (int i = 1; i < v.size(); i++) {
        if (v[i].second < cutline) {
            cutline = v[i].second;
            answer++;
        }
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    
    for (int i = 0; i < T; i++) {
        int N; cin >> N;
        vector <pair<int, int>> v;
        for (int j = 0; j < N; j++) {
            int a, b;
            cin >> a >> b;
            v.push_back(make_pair(a, b));
        }
        cout <<solution(v) << "\n";
    }
    
    return 0;
}