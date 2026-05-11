#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    i64 n, m;
    cin >> n >> m;
    vector <i64> p(n + 1), r(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> r[i];
    }

    map <i64, i64> val;
    for (int i = 1; i <= n; i++) {
        int cur = p[i];
        for (i64 j = -r[i]; j <= r[i]; j++) {
            i64 d = abs(j);
            i64 h = sqrt(r[i] * r[i] - d * d);
            val[cur + j] = max(val[cur + j], h * 2 + 1);
        }
    }

    i64 ans = 0;
    for (auto [x, y] : val) {
        ans += y;
    }
    cout << ans << '\n';
} 

int main ()
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