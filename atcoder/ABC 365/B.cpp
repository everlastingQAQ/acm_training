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
    vector <ll> v(n);
    for (ll &x : v) cin >> x;
    ll mx = *max_element(v.begin(), v.end());
    ll ans = 0;
    ll anss = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] != mx) {
            if (v[i] > ans) {
                ans = max(ans, v[i]);
                anss = i + 1;
            }   
        }
    }
    cout << anss << '\n';
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