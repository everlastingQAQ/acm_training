#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
ll n;

void solve ()
{
    cin >> n;
    vector <pair<ll, ll> > v(n);

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i].fi >> v[i].se;
        if (i == 0) {
            continue;
        }
        ans = max(abs(min(v[i - 1].se - (v[i].fi - v[i - 1].fi), 1LL * 0)), ans);
    }

    cout << ans << '\n';
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