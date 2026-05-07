#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 1e9 + 7;
const ll inf = LLONG_MAX;

ll n, q;

void solve ()
{
    cin >> n >> q;
    vector <ll> v(2 * n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for (int i = 1; i <= n; i++) {
        v[i + n] = v[i];
    }

    vector <ll> s(2 * n + 1, 0);

    for (int i = 1; i <= 2 * n; i++) {
        s[i] = s[i - 1] + v[i];
    }

    ll idx = 0;
    while (q--) {
        ll a;
        cin >> a;
        if (a == 1) {
            ll b;
            cin >> b;
            idx = (idx + b) % n;
        }else if (a == 2) {
            ll l, r;
            cin >> l >> r;
            // cout << r + idx << ' ' << l - 1 + idx << '\n';
            // cout << s[r + idx] << ' ' << s[l - 1 + idx] << '\n';
            cout << s[r + idx] - s[l - 1 + idx] << '\n';
        }
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