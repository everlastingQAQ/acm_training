#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-12;
const int mod = 998244353;

void init()     
{

}

void solve ()
{
    int n; cin >> n;
    vector <int> v(n);
    for (int &x : v) cin >> x;
    int mn = ranges::min(v);
    int ans1, ans2, ans3;
    for (int i = 0; i < n; i++) {
        if (v[i] == mn) {
            ans1 = i + 1;
        }
    }

    mn = 1e11;
    for (int i = 0; i < n; i++) {
        if (i + 1 == ans1) continue;
        mn = min(mn, v[i]);
    }

    for (int i = 0; i < n; i++) {
        if (v[i] == mn) {
            ans2 = i + 1;
        }
    }

    mn = 1e11;
    for (int i = 0; i < n; i++) {
        if (i + 1 == ans1 || i + 1 == ans2) continue;
        mn = min(mn, v[i]);
    }

    for (int i = 0; i < n; i++) {
        if (v[i] == mn) {
            ans3 = i + 1;
        }
    }

    cout << ans1 << ' ' << ans2 << ' ' << ans3 << '\n';
}   

signed main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    init();
    while (_--) {
        solve();
    }
    return 0;
}