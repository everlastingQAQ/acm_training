#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
//const ll mod = 998244353;
ll n, opt, mod, mn, mx;

//怯战
void solve ()
{
    cin >> n >> opt >> mod >> mn >> mx;
    char c;
    ll l, r, x;
    vector <ll> v(n + 2, 0);
    vector <ll> d(n + 2, 0);
    for (int cnt = 0; cnt < opt; cnt++) {
        cin >> c;
        if (c == 'A') {
            cin >> l >> r >> x;
            d[l] += x;
            d[r + 1] -= x;
        }else if (c == 'Q') {
            cin >> l >> r;
            for (int i = 1; i <= n; i++) {
                v[i] = v[i - 1] + d[i];
            }
            //cout << v[l] << ' ' << v[r] << '\n';
            ll t, ans = 0;
            for (int i = l; i <= r; i++) {
                t = ((v[i] % mod) * (i % mod)) % mod;
                if (t >= mn && t <= mn) {
                    ans++;
                }
            }
            cout << ans << '\n';
        }
    }

    ll cnt;
    cin >> cnt;

    for (int i = 1; i <= n; i++) {
        v[i] = v[i - 1] + d[i];
    }

    vector <ll> final(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        v[i] = ((v[i] % mod) * (i % mod)) % mod;
        if (v[i] >= mn && v[i] <= mx) {
            final[i] = final[i - 1] + 1;
        }else {
            final[i] = final[i - 1];
        }
    }

    while (cnt--) {
        cin >> l >> r;
        cout << final[r] - final[l - 1] << '\n';
    }
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    //cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}