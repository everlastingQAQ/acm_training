#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, x, y; cin >> n >> x >> y;
    string s; cin >> s; s = ' ' + s;
    vector <int> p(n + 1);
    for (int i = 1; i <= n; i++) cin >> p[i];

    if (accumulate(p.begin() + 1, p.end(), 0LL) > x + y) {
        cout << "NO" << '\n';
        return;
    }

    if (s == ' ' + string(n, '0') || s == ' ' + string(n, '1')) {
        if (s == ' ' + string(n, '1')) swap(x, y);
        int xx = 0;
        for (int i = 1; i <= n; i++) {
            xx += p[i] / 2 + 1;
        }
        if (xx > x || x < y + n) cout << "NO" << '\n';
        else cout << "YES" << '\n';
    }else {
        int xx = 0, yy = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '0') xx += p[i] / 2 + 1;
            else yy += p[i] / 2 + 1;
        }
        if (xx <= x && yy <= y) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
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