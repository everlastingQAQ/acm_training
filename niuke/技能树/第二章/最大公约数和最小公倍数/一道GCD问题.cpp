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
    vector <int> v(n + 1);
    int ans;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        if (i == 2) ans = v[i] - v[i - 1];
        else if (i > 2) ans = gcd(ans, v[i] - v[i - 1]);
    }

    if (ans == 1) {
        cout << 1 << ' ' << 0 << '\n';
    }else {
        cout << ans << ' ' << ans - *min_element(v.begin() + 1, v.end()) % ans << '\n';
    }

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