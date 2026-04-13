#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    vector <array <int, 2> > v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i][0] >> v[i][1];
    }
    bool ok = true;
    if (v[1][0] * v[2][1] == v[1][1] * v[2][0]) {
        for (int i = 1; i < n; i++) {
            if (v[i][0] * v[i + 1][1] != v[i][1] * v[i + 1][0]) {
                ok = false;
                break;
            }
        }
    }else {
        ok = false;
    }

    ok = true;

    if (v[2][1] % v[1][0] != 0 || v[2][1] > v[1][0]) {
        cout << "No\n";
        return;
    }

    int x = v[2][1] / v[1][0];
    int t = v[2][0] - v[1][0] * x;
    if (t % v[1][1] != 0) {
        cout << "No\n";
        return;
    }
    int y = t / v[1][1];

    if (ok) {
        cout << "Yes\n";
        return;
    }

    cout << "No\n";
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