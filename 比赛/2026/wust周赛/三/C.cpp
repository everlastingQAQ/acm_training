#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 1e9 + 7;

ll a[10] = {0, 10, 5, 10, 5, 2, 5, 10, 5, 10};
ll aa[10] = {0, 45, 20, 45, 20, 5, 20, 45, 20, 45};
 
void solve ()
{
    ll n, m; cin >> n >> m;
    if (n < m) {
        cout << 0 << '\n';
        return;
    }
    string s1 = to_string(m);
    ll t = s1[s1.size() - 1] - '0';
    if (t == 0) {
        cout << 0 << '\n';
        return;
    }
    ll temp = m;
    ll ans = t;  
    if (n > a[t]) {
        ll b = a[t] * m;
        temp = m + ((n - m) / b) * b;
        // cout << temp << '\n';
        ans += (n - m) / b * aa[t];
    }
    // cout << ans << '\n';
    for (ll i = temp + m; i <= n; i += m) {
        string ss = to_string(i);
        ans += ss[ss.size() - 1] - '0'; 
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