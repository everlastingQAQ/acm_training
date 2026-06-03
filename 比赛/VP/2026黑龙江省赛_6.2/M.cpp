#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m;
    cin >> n >> m;
    if (m <= (n + 1) / 2) {
        for (int i = 1 + m; i <= n; i++) {
            cout << i << ' ';
        }
        for (int i = 1; i <= m; i++) {
            cout << i << ' ';
        }
        cout << '\n';
    }else {
        int x = (n + 1) / 2;
        for (int i = 1 + x; i <= n; i++) {
            cout << i << ' ';
        }
        for (int i = 1; i <= x; i++) {
            cout << i << ' ';
        }
        cout << '\n';
    }
}

int32_t main ()
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