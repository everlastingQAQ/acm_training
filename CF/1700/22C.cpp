#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, m, v;
    cin >> n >> m >> v;
    if (m > n - 1 + (n * n - 5 * n + 6) / 2 || m < n - 1) {
        cout << -1 << '\n';
        return;
    }

    int x;
    if (v != 1) x = 1;
    else x = 2;

    cout << v << ' ' << x << '\n';
    for (int i = 1; i <= n; i++) {
        if (i == v || i == x) continue;
        cout << v << ' ' << i << '\n';
    }
    m -= n - 1;
    
    for (int i = 1; i <= n; i++) {
        if (i == v || i == x) continue;
        for (int j = i + 1; j <= n; j++) {
            if (m == 0) exit(0);
            if (j == v || j == x) continue;
            cout << i << ' ' << j << '\n';
            m--;
        }
    }
}
 
int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}