#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 100004;
const int M = 1000004;
struct Edge {int u, v, w;}edge[M];
bool cmp (Edge a, Edge b) {
    return a.w > b.w;
}
int s[N];

int find_set(int x) {
    if (x != s[x]) {
        s[x] = find_set(s[x]);
    }
    return s[x];
}

int n, m;

void cal () {
    sort(edge + 1, edge + m + 1, cmp);
    for (int i = 1; i <= n; i++) {
        s[i] = i;
    }
    int ans = 0, cnt = 0;
    for (int i = 1; i <= m; i++) {
        if (cnt == n - 1) break;
        int e1 = find_set(edge[i].u);
        int e2 = find_set(edge[i].v);
        if (e1 == e2) continue;
        else {
            ans += edge[i].w;
            s[e1] = e2;
            cnt++;
        }
    }
    if (cnt == n - 1) {
        cout << ans << '\n';
    }else {
        cout << -1 << '\n';
    }
}

void solve ()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
    }
    cal();
} 
    
int32_t main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 