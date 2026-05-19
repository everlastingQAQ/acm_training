#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n, x1, x2, k;
    cin >> n >> x1 >> x2 >> k;
    if (n == 2 || n == 3) {
        cout << 1 << '\n';
        return;
    }
    if (x2 < x1) swap(x1, x2);
    int len = min(x2 - x1, n + x1 - x2);
    cout << len + k << '\n';
}

int32_t main()
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