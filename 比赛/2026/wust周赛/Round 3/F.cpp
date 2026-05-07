#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
	int n;
    cin >> n;
    vector <int> v(n + 1);
    vector <int> vis(n + 5, 0);
    vector <int> a, b, c;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        if (v[i] == 2) c.push_back(i);
        else if (v[i] == 1) b.push_back(i);
        else a.push_back(i);
    }

    int ans = 0;
    for (int i = 1; i < c.size() - 1; i++) {
        if (i >= c.size()) break;
        if (!vis[c[i]]) ans++;
        vis[c[i]] = 1;
        vis[c[i] - 1] = 1;
        vis[c[i] + 1] = 1;
    }

    if (c.size() == 1) {
        ans++;
        vis[c[0]] = 1;
        if (c[0] > 1) vis[c[0] - 1] = 1;
        if (c[0] < n) vis[c[0] + 1] = 1;
    }else if (c.size() == 2) {
        ans++;
        vis[c[0]] = 1;
        if (c[0] > 1) vis[c[0] - 1] = 1;
        if (c[0] < n) vis[c[0] + 1] = 1;
        if (!vis[c[1]]) ans++;
        vis[c[1]] = 1;
        if (c[1] > 1) vis[c[1] - 1] = 1;
        if (c[1] < n) vis[c[1] + 1] = 1;
    }

    for (int i = 1; i < b.size() - 1; i++) {
        if (i >= b.size()) break;
        if (!vis[b[i]]) ans++;
        if (!vis[b[i] - 1]) {
            vis[b[i] - 1] = 1;
        }else {
            vis[b[i] + 1] = 1;
        }
    }

    if (b.size() == 1) {
        if (!vis[b[0]]) ans++;
        vis[b[0]] = 1;
        if (b[0] > 1 && !vis[b[0] - 1]) {
            vis[b[0] - 1] = 1;
        }else if (b[0] < n && !vis[b[0] + 1]) {
            vis[b[0] + 1] = 1;
        }
    }else if (b.size() == 2) {
        if (!vis[b[0]]) ans++;
        vis[b[0]] = 1;
        if (b[0] > 1 && !vis[b[0] - 1]) {
            vis[b[0] - 1] = 1;
        }else if (b[0] < n && !vis[b[0] + 1]) {
            vis[b[0] + 1] = 1;
        }
        if (!vis[b[1]]) ans++;
        vis[b[1]] = 1;
        if (b[1] > 1 && !vis[b[1] - 1]) {
            vis[b[1] - 1] = 1;
        }else if (b[1] < n && !vis[b[1] + 1]) {
            vis[b[1] + 1] = 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) ans++;
    }
    cout << ans << '\n';
} 

int main ()
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