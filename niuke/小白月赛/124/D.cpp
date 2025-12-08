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
 
ll a, b, l, r;

void solve ()
{
    cin >> a >> b >> l >> r;
    ll t = b - a;
    ll ans = 0;
    for (int i = 1; i * i <= t; i++) {
        if (t % i != 0) continue;
        ll temp1 = t / i + b;
        ll temp2 = i + b;
        if (temp1 >= l && temp1 <= r) ans++;
        if (temp2 >= l && temp2 <= r) ans++;
        if (temp1 == temp2 && temp2 >= l && temp2 <= r) ans--;
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