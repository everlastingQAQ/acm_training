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
    
    vector <ll> a;

    ll ans = n;
    for (int i = 1; i <= n; i++) {
        a.push_back(v[i]);
        ll m = a.size();
        while (m >= 4 && a[m - 1] == a[m - 2] && a[m - 2] == a[m - 3] && a[m - 3] == a[m - 4]) {
            a.pop_back(), a.pop_back(), a.pop_back(), a.pop_back();
            ans -= 4;
            m -= 4;
        }
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