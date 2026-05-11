#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
ll n, m;

void solve ()
{
    cin >> n >> m;
    vector<ll> a;
    vector<pair<ll, ll> > v(m);

    for (int i = 0; i < n; i++) {
        ll t;
        cin >> t;
        a.push_back(t);
    }

    for (int i = 0; i < m; i++) {
        cin >> v[i].fi;
    }
    for (int i = 0; i < m; i++) {
        cin >> v[i].se;
    }

    sort(v.begin(), v.end(), [] (auto &a1, auto &b1) {
        if (a1.se != b1.se) {
            return a1.se > b1.se;
        }
        return a1.fi < b1.fi;
    });

    sort(a.begin(), a.end());

    ll l = 0, r = 0;
    ll ans = 0;

    while (r < m && l < n) {
        while (l < n && a[l] < v[r].fi) {
            l++;
        }

        if (v[r].se != 0) {
            ans++;
            r++;
            if (r < m) {
                a[0] = v[r].se;
            }
        }else if (v[r].se == 0) {
            ans++;
            l++;
            r++;
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