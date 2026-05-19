#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n, m;
    cin >> n >> m;
    if (n == m) {
        cout << 0 << ' ' << 8 << string(n - 1, '9');
        return;
    }
    if (n > m) swap(n, m);
    if (m - n - 1 >= 1) cout << string(m - n - 1, '9') << string(n - 1, '0') << 1 << ' ';
    else cout << 1 << ' ';
    cout << string(m - n, '9') << 8 << string(n - 1, '9');
}

int32_t main()
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