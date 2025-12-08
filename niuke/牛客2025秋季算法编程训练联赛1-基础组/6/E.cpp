#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 1e9 + 7;
const ll inf = LLONG_MAX;

ll n;

void solve ()
{
    cin >> n;
    vector <ll> a(n + 1);
    vector <ll> b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) { 
        cin >> b[i];
    }
    sort(a.begin() + 1, a.end());
    sort(b.begin() + 1, b.end());

    ll l = 0, r = 1;
    ll ans = 1;

    while (r <= n) {
        if (l < n && a[l + 1] <= b[r]) {
            l++;
        }else {
            ll t = (l - r + 1) % mod;
            ans *= max(0LL, t);
            ans %= mod;
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
    //cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}