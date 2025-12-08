#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-12;
const ll mod = 1e9 + 7;

ll n, m, a, b;

void solve ()
{
    cin >> n >> m >> a >> b;
    ll t1 = a - 1;
    ll t2 = n - a;
    ll t3 = b - 1;
    ll t4 = m - b;
    ll mxn = max(t1, t2);
    ll mxm = max(t3, t4);

    auto findx = [&] (ll x) -> ll {
        if (x == 1) return 0;
        ll t = sqrt(x);
        while (t * (t + 1) / 2 < x) {
            t++;
        }
        return t - 1;
    };

    // cout << t1 << ' ' << t2 << ' ' << t3 << ' ' << t4 << '\n';

    if (mxn > mxm) {
        ll ans1 = findx(min(t1 + 1, t2 + 1));
        ll ans2 = findx(m);
        cout << ans1 + ans2 + 1 << '\n';
    }else {
        ll ans1 = findx(n);
        ll ans2 = findx(min(t3 + 1, t4 + 1));
        cout << ans1 + ans2 + 1 << '\n';
    }
}

int main ()
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