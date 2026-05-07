#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 998244353;
 
ll n, q;

void solve ()
{
    cin >> n >> q;
    vector <ll> a(n + 1);
    vector <ll> b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    vector <ll> mn(n + 1);
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        mn[i] = min(a[i], b[i]);
        sum += mn[i];
    }

    while (q--) {
        ll x, v;
        char c;
        cin >> c >> x >> v;
        if (c == 'A') {
            if (v < mn[x]) {
                sum -= mn[x] - v;
                a[x] = v;
                mn[x] = v;
            }else {
                a[x] = v;
                ll t = mn[x];
                mn[x] = min(a[x], b[x]);
                sum += mn[x] - t;
            }
        }else {
            if (v < mn[x]) {
                sum -= mn[x] - v;
                b[x] = v;
                mn[x] = v;
            }else {
                b[x] = v;
                ll t = mn[x];
                mn[x] = min(a[x], b[x]);
                sum += mn[x] - t;
            }
        }
        cout << sum << '\n';
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