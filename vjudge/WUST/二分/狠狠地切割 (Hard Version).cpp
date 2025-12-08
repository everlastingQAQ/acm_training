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
    vector <ll> v(n);

    for (ll &i : v) {
        cin >> i;
    }

    unordered_set <ll> cut;
    for (int i = 0; i < m; i++) {
        ll x;
        cin >> x;
        cut.insert(x);
    }

    ll ans = 0;
    for (int i = 0; i < n - 1; i++) {
        if (!cut.count(v[i]) && cut.count(v[i + 1])) {
            ans++;
        }
    }
    if (!cut.count(v[n - 1])) {
        ans++;
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