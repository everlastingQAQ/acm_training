#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    vector <int> x(n + 1);
    vector <int> y(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    sort(x.begin() + 1, x.end());
    x.erase(unique(x.begin() + 1, x.end()), x.end());
    sort(y.begin() + 1, y.end());
    y.erase(unique(y.begin() + 1, y.end()), y.end());

    int mx = x.size() - 1;
    int my = y.size() - 1;
    // cout << mx << ' ' << my << '\n';

    int ansx, ansy;
    if (mx & 1) {
        ansx = x[mx / 2 + 1];
    }else {
        ansx = (x[mx / 2] + x[mx / 2 + 1]) / 2;
    }
    if (my & 1) {
        ansy = y[my / 2 + 1];
    }else {
        ansy = (y[my / 2] + y[my / 2 + 1]) / 2;
    }

    cout << ansx << ' ' << ansy << '\n';
} 
    
int32_t main ()
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