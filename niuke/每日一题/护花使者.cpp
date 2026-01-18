#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

void solve ()
{
    int n; cin >> n;
    vector <array<int, 2> > v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1];
    }

    ranges::sort(v, [] (auto a1, auto b1) {
        return a1[0] * b1[1] > a1[1] * b1[0];
    });

    int ans = 0;
    int t = 0;
    for (int i = 0; i < n; i++) {
        ans += v[i][0] * t;
        t += 2 * v[i][1];
    }

    cout << ans << '\n';
}   

signed main ()
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