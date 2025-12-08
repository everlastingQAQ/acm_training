#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
const ll inf = LLONG_MAX;

ll n, k;

ll qpow(ll a, ll b)
{
    ll ans = 1;
    while (b) {
        if (b & 1) {
            ans = ans * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

void solve ()
{
    cin >> n >> k;
    vector <ll> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }  

    ll l = 1, r = 1;

    ll sum = 1;
    ll ans = 0;
    while (r <= n) {
        if (v[r] != 0) {
            sum = (sum * v[r]) % mod;
            if ((r - l + 1) % k == 0) {
                ans = max(ans, sum);
                sum = sum * qpow(v[l], mod - 2) % mod;
                l++;
            }
        }else {
            l = r + 1;
            sum = 1;
        }
        r++;
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