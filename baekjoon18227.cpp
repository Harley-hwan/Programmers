#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

// 백준 18227번: 성대나라의 물탱크 (세크먼트 트리)

// 펜윅 트리: 세그먼트 트리에 비해 메모리 소모량 적고, 코드 간단.
// 세그먼트 트리에서 한단계 응용된 자료구조.

long long Fenwick_Tree[200001], depth[200001];
long long tin[200001], tout[200001];
int n, c, u, v, q;
int cnt = 0;
vector<int> g[200001];
// 1. 펜윅트리는 비트를 이용해서 생성하게 된다.
// 2. 각 Index를 2진수로 표현했을 때, '1'이 존재하는 가장 최하위 비트의 값을 찾는다. = u
// 3. 해당 Index부터 u칸 앞까지의 구간연산에 대한 결과값을 갖는다.

void dfs(int x) {
    tin[u] = ++cnt;
    for (int nx : g[x]) {
        if (tin[nx]) continue;
        depth[nx] = depth[x] + 1;   //depth
        dfs(nx);
    }
    tout[x] = cnt;
}

void Update(int Idx)
{
    while (Idx < 200001)
    {
        Fenwick_Tree[Idx]++;
        Idx += (Idx & -Idx);
    }
}
long long Sum(int Idx)
{
    long long result = 0;
    while (Idx > 0)
    {
        // Index번호 + ('1'이 존재하는 최하위 비트) !
        // -Idx : 2의 보수 ( 현재 값을 뒤집고 1을 더한 거 )
        // ex) (Idx)1001(9) -> 0110 -> 0111(-Idx)
        // 1001 & 0111 = 0001
        result += Fenwick_Tree[Idx];
        Idx -= (Idx & -Idx);
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> c;

    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    depth[c] = 1;
    dfs(c);
    cin >> q;
    while (q--) {
        cin >> u >> v;

        // 물이 root부터 채워지니까, u번 정점 채울때 tin[u] 업데이트해주면
        // 그 위는 [tin, tout]에 항상 tin[u]가 들어있다고 볼 수 있음.
        // 부분합 쿼리로 tin, tout의 합을 구하면 그게 이 정점 밑의 서브트리에서
        // 물을 채운 횟수를 의미하므로
        if (u & 1) Update(tin[v]);  
        else {
            // Sum로 tin, tout 합 구하면 그게 이 정점 밑의 서브트리에서
            // 물을 채운 횟수를 의미하므로, 횟수 * 각각의 깊이(dfs)
            cout << (Sum(tout[v]) - Sum(tin[v] - 1)) * depth[v] << '\n';
        }
    }

    return 0;
}