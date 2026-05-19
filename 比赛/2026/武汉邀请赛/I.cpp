#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve1 ()
{
    int n;
    cin >> n;
    vector <vector <int> > e(n + 1);
    vector <int> ind(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
        ind[u]++;
        ind[v]++;
    }
    
    int r = 0;
    for (int i = 1; i <= n; i++) {
        if (ind[i] == 1) {
            r = i;
        }
        sort(e[i].begin(), e[i].end(), [&] (auto a, auto b) {
            return ind[a] > ind[b]; 
        });
    }

    vector <int> vis(n + 1);
    vector <int> ans;
    ans.reserve(n);
    int rr = e[r][0];
    queue <int> q;
    q.push(rr);
    vis[rr] = true;
    vis[r] = true; 
    int sum = 1 + 1 + e[rr].size() - 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u != rr) sum += e[u].size() - 1;
        if (sum == n && e[u].size() == 1) {
            continue;
        }
        ans.push_back(u);
        for (auto v : e[u]) {
            if (vis[v]) continue;
            q.push(v);
            vis[v] = true;
        }
    }

    if (ans.size() <= n - 3) {
        cout << ans.size() << '\n';
        for (auto x : ans) {
            cout << x << ' ';
        }
    }else {
        cout << n - 3 << '\n';
        for (int i = 0; i < n - 3; i++) {
            cout << ans[i] << ' ';
        }
    }
    
}

void solve2 ()
{
    int n, m;
    cin >> n >> m;
    vector <int> v(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> v[i];
    }
    vector <array <int, 2> > ans;
    ans.reserve(n);
    ans.push_back({1, 2});
    int cur = 0;
    int c = 3;
    int r = 2;
    int cnt = 0;
    for (int i = 1; i <= m; i++) {
        int t = v[i] - cur;
        if (i != 1) t++;
        else t--;
        cur = v[i];
        for (int j = 0; j < t; j++) {
            ans.push_back({r, c++});
        }
        r++;
    }
    if (c != n + 1) {
        ans.push_back({r, c});
    }
    for (auto [u, v] : ans) {
        cout << u << ' ' << v << '\n';
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int op;
    cin >> op;
    if (op == 1) {
        solve1();
    }else {
        solve2();
    }
    return 0;
}