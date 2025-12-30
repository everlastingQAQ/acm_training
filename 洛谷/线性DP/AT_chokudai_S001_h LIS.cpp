#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-12;
const ll mod = 998244353;

void solve ()
{
    ll n; cin >> n;
    vector <ll> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    
    vector <ll> a(n + 1);
    a[1] = v[1];
    ll ans = 1;
    for (int i = 2; i <= n; i++) {
        ll pos = lower_bound(a.begin() + 1, a.begin() + 1 + ans, v[i]) - a.begin();
        a[pos] = v[i];
        if (pos > ans) ans++;
    }

    cout << ans << '\n';
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