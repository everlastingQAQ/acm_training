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
    ll n, m; cin >> n >> m;
    string s, t; cin >> s >> t;

    ll ans = 1e16;
    for (int i = 0; i <= n - m; i++) {
        string k = t;
        ll sum = 0;
        for (int j = 0; j < m; j++) {
            ll a = s[i + j] - '0', b = t[j] - '0';
            // cout << a << ' ' << b << ' ' << i << '\n';
            if (a < b) sum += 10 + a - b;
            else sum += a - b;
        }
        ans = min(sum, ans);
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