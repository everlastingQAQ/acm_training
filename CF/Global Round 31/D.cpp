#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 1e9 + 7;

void solve ()
{
    ll n; cin >> n;
    vector <ll> v(n + 1), d(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        d[i] = v[i] - v[i - 1];
    }

    ll cur = 0, pos = 1;
    ll l = 0, r = 1e16;
    ll ans = n - 1;

    for (int i = 2; i <= n; i++) {
        cur = d[i] - cur;
        if (((i - pos) & 1) == 0) {
            r = min(r, cur);
            if (i < n - 1) l = max(l, cur - d[i + 1]);
        }else {
            l = max(l, -cur);
            if (i < n - 1) r = min(r, d[i + 1] - cur);
        }
        if (l >= r) {
            // cout << i << '\n';
            ans--;
            l = 0, r = 1e16;
            cur = 0;
            pos = i + 1;
        }
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