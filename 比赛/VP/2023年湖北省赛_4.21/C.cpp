#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m;
    cin >> n >> m;
    if (n == m) {
        cout << n << '\n';
        return;
    }
    if (n > m) swap(n, m);

    if (n == 1) {
        cout << m / 2 + 1 << '\n';
        return;
    }else if (n == 2) {
        cout << m / 2 + 1 + 1 << '\n';
        return;
    }

    if (!(n & 1) && !(m & 1)) {
        int ans = n / 2 + 1 + m / 2 + 1 - 1;
        cout << ans - 1 << '\n';
        return;
    }

    int ans = n / 2 + 1 + m / 2 + 1 - 1;
    cout << ans << '\n';
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