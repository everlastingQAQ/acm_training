#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 1e6 + 5;
const double eps = 1e-5;
const ll mod = 998244353;
ll n;

void solve ()
{
    while (cin >> n && n != 0) {
        vector <pair<ll, ll> > v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i].fi >> v[i].se;
        }

        sort(v.begin(), v.end(), [](const pair<ll, ll> &a1, const pair<ll, ll> &b1) {
            return a1.se < b1.se;
        });

        ll ans = 0;
        ll t = 0;
        for (int i = 0; i < n; i++) {
            if (v[i].fi >= t) {
                t = v[i].se;
                ans++;
            }
        }
        cout << ans << '\n';
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