#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n; cin >> n;
    vector <array<int, 3> > v(n);
    for (int i = 0; i < n; i++) cin >> v[i][0] >> v[i][1] >> v[i][2];

    ranges::sort(v, [] (auto a1, auto b1) {
        return a1[2] < b1[2];
    });

    double ans = 0;
    for (int i = 1; i < n; i++) {
        ans += sqrt((v[i][0] - v[i - 1][0]) * (v[i][0] - v[i - 1][0]) + (v[i][1] - v[i - 1][1]) * (v[i][1] - v[i - 1][1]) + (v[i][2] - v[i - 1][2]) * (v[i][2] - v[i - 1][2]));
    }
    cout << fixed << setprecision(3) << ans << '\n';
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