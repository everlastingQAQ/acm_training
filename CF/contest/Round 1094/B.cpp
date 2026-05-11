#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <int> a, b;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        if (i & 1) a.push_back(t);
        else b.push_back(t);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int c0 = 0, c1 = 0;
    for (int i = 1; i <= m; i++) {
        int t;
        cin >> t;
        if (t & 1) c1++;
        else c0++;
    }

    bool ok = false;
    while (c1-- && !a.empty()) {
        if (ok && a.back() <= 0) break;
        a.pop_back();
        ok = true;
    }
    ok = false;
    while (c0-- && !b.empty()) {
        if (ok && b.back() <= 0) break;
        b.pop_back();
        ok = true;
    }

    i64 ans = 0;
    for (auto x : a) {
        // cout << x << " ";
        ans += x;
    }
    for (auto y : b) {
        // cout << y << ' ';
        ans += y;
    }
    cout << ans << '\n';
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}