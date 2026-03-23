#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    double m, n;
    cin >> m >> n;
    vector <array <double, 2> > v(n + 1);
    string t = "FemboyLovestory";
    bool ok = false;
    double x = -1.0;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        if (s == t) {
            ok = true;
        }
        i64 a, c;
        cin >> a >> c;
        v[i][0] = 1.0 * a * c / 100;
        if (s == t) {
            v[i][1] = 1;
            x = v[i][0];
        }else {
            v[i][1] = 0;
        }
    }

    sort(v.begin() + 1, v.end());

    if (!ok) {
        cout << 0 << '\n';
        return;
    }

    m -= x;
    if (m < 0) {
        cout << 0 << '\n';
        return;
    }
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        if (v[i][1] == 1) continue;
        m -= v[i][0];
        if (m >= 0) ans++;
        else break;
    }

    cout << ans << '\n';
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