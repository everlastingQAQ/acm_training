#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector <i64> v(n + m + 10);
    for (int i = 1; i <= n + m + 1; i++) {
        cin >> v[i];
    }
    bool ok = false;
    for (int i = 1; i <= n; i++) {
        if (v[i] + v[i + 1] < 0) {
            ok = true;
            break;
        }
    }
    if (v[1] + v[n + 1] < 0) ok = true;
    for (int i = n + 2; i < n + m + 1; i++) {
        if (v[i] + v[i + 1] < 0) {
            ok = true;
            break;
        }
    }
    if (v[1] + v[n + 2] < 0) ok = true;
    if (v[1] + v[n + m + 1] < 0) ok = true;
    
    if (ok) {
        while (q--) {
            int u, v;
            cin >> u >> v;
            cout << 0 << '\n';
        }
        return;
    }

    vector <i64> p1(n + 10);
    for (int i = 2; i <= n + 1; i++) {
        p1[i] = p1[i - 1] + v[i];
    }
    vector <i64> p2(n + m + 10);
    for (int i = n + 2; i <= n + m + 1; i++) {
        p2[i] = p2[i - 1] + v[i];
    }

    while (q--) {
        int s, t;
        cin >> s >> t;
        if (s > t) swap(s, t);
        i64 ans = 0;
        if (s == t) {
            ans = v[s];
        }else if (s == 1) {
            if (t <= n + 1) {
                ans = min(p1[t] + v[1], p1[n + 1] - p1[t - 1] + v[1]);
            }else {
                ans = min(p2[t] + v[1], p2[n + m + 1] - p2[t - 1] + v[1]);
            }
        }else if (s <= n + 1 && t <= n + 1) {
            ans = min(p1[t] - p1[s - 1], p1[s] + p1[n + 1] - p1[t - 1] + v[1]);
        }else if (s <= n + 1 && t > n + 1) {
            ans = min(p1[s], p1[n + 1] - p1[s - 1]) + v[1] + min(p2[t], p2[n + m + 1] - p2[t - 1]);
        }else {
            ans = min(p2[t] - p2[s - 1], p2[s] + p2[n + m + 1] - p2[t - 1] + v[1]);
        }
        cout << max(0LL, ans) << '\n';
    }
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