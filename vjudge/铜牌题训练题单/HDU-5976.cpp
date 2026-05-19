#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7;

void solve ()
{
    int n;
    cin >> n;
    int ans = 1;
    map <int, int> mp;
    auto dfs = [&] (auto self, int m) -> int {
        int x = m / 2, y = m - m / 2;
        while (mp[x] || mp[y]) {
            x--;
            y++;
        }
        if (x == y) x--, y++;
        if (x == 0) return m;
        if (x * y <= m) ans = (ans * m) % mod;
        else {
            self(self, x);
            self(self, y);
        }
    };
    dfs(dfs, n);
    cout << ans << '\n';
}   

int32_t main ()
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