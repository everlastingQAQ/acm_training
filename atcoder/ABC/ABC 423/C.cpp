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

ll n, p;

void solve ()
{
    cin >> n >> p;
    vector <ll> v(n + 1);
    for (ll i = 1; i <= n; i++) {
        cin >> v[i];
    }

    ll l = n + 1, r = 0;
    ll cnt = 0;
    for (ll i = 1; i <= n; i++) {
        if (v[i] == 0) {
            l = min(i, l);
            r = max(i, r);
            cnt++;
        }
    }

    if (l == n + 1) {
        cout << 0 << '\n';
        return;
    }

    l = min(l, p + 1);
    r = max(r, p);

    cout << (r - l + 1) * 2 - cnt << '\n';

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