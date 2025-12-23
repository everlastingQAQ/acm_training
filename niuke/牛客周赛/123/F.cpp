#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, char>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 1e9 + 7;

void solve ()
{
    ll n; cin >> n;
    vector <ll> v(n);
    for (ll &x : v) cin >> x;
    map <ll, ll> mp;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (mp[v[i] - 1] <= mp[v[i]] && mp[v[i] + 1] <= mp[v[i]]) {
            ans++;
        }else if (mp[v[i] - 1] > mp[v[i]] && mp[v[i] + 1] > mp[v[i]]) {
            ans--;
        }
        mp[v[i]]++;
        cout << ans << ' ';
    }
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}   