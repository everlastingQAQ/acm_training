#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    vector <int> v;
    v.reserve(n + 1);
    int mn = 1e9;
    int mx = -1;
    bool op = 0;
    int ini = 0;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        if (i == 1) ini = t;
        if (op == 0) {
            if (t >= mx) {
                cout << 1;
                mx = t;
            }else if (t <= ini) {
                cout << 1;
                op = 1;
                mn = t;
            }else {
                cout << 0;
            }
        }else {
            if (t <= ini && t >= mn) {
                cout << 1;
                mn = t;
            }else {
                cout << 0;
            }
        }
    }
    cout << '\n';
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