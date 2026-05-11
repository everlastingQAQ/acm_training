#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 998244353;
const ll inf = LLONG_MAX;

ll n, k;

void solve ()
{
    cin >> n >> k;
    vector <ll> v(n + 1);
    vector <ll> a(k + 1);
    for (ll i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for (ll i = 1; i <= k; i++) {
        cin >> a[i];
    }
    
    sort(v.begin() + 1, v.end(), greater<ll>());
    sort(a.begin() + 1, a.end());
    
    vector <ll> s(k + 1);
    for (ll i = 1; i <= k; i++) {
        s[i] = s[i - 1] + a[i];
    }

    ll ans = 0;
    for (ll i = 1, j = 1; i <= n; i++) {
        if (j <= k && i == s[j]) {
            j++;
        }else {
            ans += v[i];
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