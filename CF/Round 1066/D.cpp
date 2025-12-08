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

ll n, l, r;

void solve ()
{
    cin >> n >> l >> r;
    vector <ll> v(n + 1);
    ll posl = 1;
    ll posr = n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    for (int i = 1; i <= n; i++) {
        if (v[i] <= l) {
            posl = i;
        }
    }

    for (int i = n; i > 0; i--) {
        if (v[i] >= r) {
            posr = i;
        }
    }

    if (l == r) {
        ll q = 0;
        for (int i = 1; i <= n; i++) {
            q += abs(v[i] - l);
        }
        cout << q << '\n';
        return;
    }

    ld t = (l + r) / 2;
    ll pos;

    if (l <= v[1] && r >= v[n]) {
        ld mn = inf;
        for (int i = 1; i <= n; i++) {
            if (fabs(1.0 * v[i] - t) < mn) {
                mn = 1.0 * v[i] - t;
                pos = i;
            }
        }
    }else {
        pos = round((posl + posr) / 2);
    }

    ll ans = 0;
    //cout << pos << '\n';
    ll b = (v[1] + v[n]) / 2;
    for (int i = 1; i <= n; i++) {
        if (i == pos) continue;
        ans += abs(b - v[i]);
    }

    cout << ans << '\n';

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