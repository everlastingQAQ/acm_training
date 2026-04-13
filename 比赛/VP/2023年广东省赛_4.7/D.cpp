#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <array <int, 2> > a; a.reserve (n); // duju
    vector <array <int, 2> > b; b.reserve (n);

    int tot = 0;
    for (int i = 0; i < n; i ++) {
        int x, y;
        cin >> x >> y;
        if (x < y) {
            a.push_back ({x, y});
            tot += y;
        } else {
            b.push_back ({x, y});
        }
    }

    sort (a.begin(), a.end(), [] (auto &x, auto &y) {
        return x[1] - x[0] < y[1] - y[0];
    });

    int k = a.size();

    if (n == 1) {
        if (!a.empty()) {
            cout << a[0][1] << '\n';
        } else {
            cout << b[0][1] << '\n';
        }
        return;
    }

    if (k == n && m >= 2 * k - 1) {
        cout << tot << '\n';
    } else if (m - n >= k) {
        if (k == n - 1) {
            cout << max (tot - a[0][1] + a[0][0] + b[0][0], tot + b[0][1]) << '\n';
        } else {
            int ans = tot;
            for (int i = 0; i < b.size(); i ++) {
                ans += b[i][0];
            }
            cout << ans << '\n';
        }
    } else {
        int nm = k - (m - n);
        int ans = tot;
        for (int i = 0; i < nm; i ++) {
            ans = ans - a[i][1] + a[i][0];
        }

        for (int i = 0; i < b.size(); i ++) {
            auto [x, y] = b[i];
            ans = ans + x;
        }

        cout << ans << '\n';
    }
} 

int32_t main ()
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