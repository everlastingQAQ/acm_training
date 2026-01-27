#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

void solve ()
{
    int x, y; cin >> x >> y;
    queue <array<int, 2> > q;
    q.push({x, 0});

    vector <int> v(1e5 + 1, 0);
    while (q.size()) {
        auto [t, val] = q.front();
        q.pop();
        v[t] = val;
        if (t == y) break;
        if (t * 2 <= 1e5 && v[t * 2] == 0) q.push({t * 2, val + 1});
        if (t + 1 <= 1e5 && v[t + 1] == 0) q.push({t + 1, val + 1});
        if (t - 1 > 0 && v[t - 1] == 0) q.push({t - 1, val + 1});
    }

    cout << v[y] << '\n';
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