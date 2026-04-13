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
 
ll n;

void solve ()
{   
    cin >> n;
    ll u, v;
    vector<vector<ll> > e(n + 1);
    for (ll i = 0; i < n - 1; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    if (n == 2) {
        cout << 2 << ' ' << 0 << '\n';
        return;
    }

    ll mx = 0;
    ll pos = 0;
    for (ll i = 1; i <= n; i++) {
        ll cnt = 0;
        for (auto x : e[i]) {
            cnt += e[x].size() - 1;
        }
        if (cnt >= mx) {
            mx = cnt;
            pos = i;
        }
    }

    cout << pos << ' ' << mx << '\n';
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