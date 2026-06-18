#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(n + 1), a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    if (n == 1) {
        cout << 1 << '\n';
        return;
    }

    for (int i = 1; i < n; i++) {
        a[i] = llabs(v[i + 1] - v[i]);
    }

    using arr2 = array <int, 2>;
    vector <arr2> nxt;
    int ans = 1;
    for (int i = 1; i < n; i++) {
        vector <arr2> cur;
        if (a[i] != 1) cur.push_back({a[i], i});
        for (auto [x, y] : nxt) {
            int t = gcd(x, a[i]);
            if (t != 1) {
                if (cur.empty() || cur.back()[0] != t) {
                    cur.push_back({t, y});
                }else {
                    cur.back()[1] = y;
                }
            }
        }
        for (auto [x, y] : cur) {
            ans = max(ans, i - y + 2);
        }
        nxt = cur;
    }

    cout << ans << '\n';
}

int32_t main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}