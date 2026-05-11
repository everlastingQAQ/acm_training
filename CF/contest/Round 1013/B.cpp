#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, x; cin >> n >> x;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    ranges::sort(v | views::drop(1), greater<int>());

    int idx = 1;
    int ans = 0;
    while (idx <= n && v[idx] >= x) {
        idx++;
        ans++;
    }
    int l = idx, r = idx + 1;
    while (r <= n) {
        while (r <= n && v[r] * (r - l + 1) < x) {
            r++;
        }
        if (r <= n && v[r] * (r - l + 1) >= x) ans++;
        l = r + 1;
        r += 2;
    }

    cout << ans << '\n';
}   
    
signed main ()
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