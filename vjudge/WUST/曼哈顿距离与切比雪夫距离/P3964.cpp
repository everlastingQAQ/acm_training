#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <i64> x(n + 1), y(n + 1), xx(n + 1), yy(n + 1);
    for (int i = 1; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        x[i] = xx[i] = u + v;
        y[i] = yy[i] = u - v;
    }
    sort(xx.begin() + 1, xx.end());
    sort(yy.begin() + 1, yy.end());
    vector <i64> px(n + 1), py(n + 1);
    for (int i = 1; i <= n; i++) {
        px[i] = px[i - 1] + xx[i];
        py[i] = py[i - 1] + yy[i];
    }

    auto cal = [&] (i64 x, i64 y) -> i64 {
        int posx = lower_bound(xx.begin() + 1, xx.end(), x) - xx.begin();
        int posy = lower_bound(yy.begin() + 1, yy.end(), y) - yy.begin();
        i64 cx = posx * x - px[posx] + px[n] - px[posx] - (n - posx) * x;
        i64 cy = posy * y - py[posy] + py[n] - py[posy] - (n - posy) * y;
        return cx + cy;
    };

    i64 ans = 1e18;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, cal(x[i], y[i]));
    }
    cout << ans / 2 << '\n';
}

int main ()
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