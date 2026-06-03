#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(n + 1), d(n + 1);
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        d[i] = v[i] - v[i - 1];
        if (i != 1) mx = max(mx, -d[i]);
    }
    // cout << mx << '\n';
    for (int i = 2; i <= n; i++) {
        if (v[i] + mx < v[i - 1]) {
            // cout << i << ' ' << v[i] << ' ' << v[i - 1] << '\n';
            cout << "NO\n";
            return;
        }else {
            if (v[i] < v[i - 1]) {
                v[i] += mx;
            }
        }
    }

    cout << "YES\n";
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
