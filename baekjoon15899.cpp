#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 백준 18227번: 성대나라의 물탱크 (세크먼트 트리)
vector<int> tree[800001], g[200001];
int tin[20001], tout[200001], col[200001];
const int mod = 1e9 + 7;
int n, m, c, x, u, v, a, b;
int cnt = 0;

void dfs(int x) {
    tin[x] = ++cnt;
    for (int nx : g[x]) {
        if (tin[nx]) continue;
        dfs(nx);
    }
    tout[x] = cnt;
}

int query(int node, int start, int end, int left, int right, int k) {
    // case 1: [start, end] 앞 뒤에 [left, right]가 있는 경우, 
    // 겹치지 않기 때문에 탐색을 더 이상 할 필요가 없다. 
    if (left > end || right < start) return 0; 
    
     // case 2: [start, end]가 [left, right]에 포함
    if (left <= start && end <= right) {
        return upper_bound(tree[node].begin(), tree[node].end(), k) - tree[node].begin();
    }
      
     
    // case 3, 4: 왼쪽 자식과 오른쪽 자식을 루트로 하는 트리에서 다시 탐색 시작 
    int mid = (start + end) / 2; 
    return query(node*2, start, mid, left, right, k) + 
    query(node*2+1, mid+1, end, left, right, k); 
}

void update(int node, int start, int end, int index, int diff) {
    if (index < start || index > end) return; 
    // case 2 
    tree[node].push_back(diff); 
    
    // case 1 
    // 리프 노드가 아닌 경우 자식도 변경해줘야 하기 때문에, 
    // 리프 노드인지 검사를 하고 아래 자식 노드를 갱신해준다. 
    if (start != end) {
        int mid = (start + end) / 2; 
        update(node*2, start, mid, index, diff); 
        update(node*2+1, mid+1, end, index, diff); 
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m >> c;

    for (int i = 1; i <= n; i++) {
        cin >> col[i];
    }
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    //     for (int i = 0; i < N-1; i++ {
    //     int start, end; cin >> start >> end;
    //     v[start].push_back(end);
    //     v[end].push_back(start);
    dfs(1);
    for (int i = 1; i <= n; i++) {
        update(1, 1, n, tin[i], col[i]);
    }

    for (int i = 1; i <= 800000; i++) {
        sort(tree[i].begin(), tree[i].end());
    }

    int answer = 0;
    while (m--) {
        cin >> a >> b;
        answer += query(1, 1, n, tin[a], tout[a], b);
        answer %= mod;
    }

    cout << answer << "\n";

    return 0;
}