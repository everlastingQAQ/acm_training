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

vector <ll> a;
vector <ll> p3(22);

void init ()
{
    p3[0] = 1;
    for (ll i = 1; i <= 21; i++) {
        p3[i] = p3[i - 1] * 3;
    }

    a.push_back(3);
    for (ll i = 1; i < 21; i++) {
        a.push_back(p3[i + 1] + i * p3[i - 1]);
    }
}

void solve ()
{
    ll n; cin >> n;
    ll t = p3[20];
    ll ans = 0;
    for (int i = 20; i >= 0; i--) {
        ll x = n / t;
        ans += x * a[i];
        n -= x * t;
        t /= 3;
    }
    cout << ans << '\n';
}
 
int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    init();
    while (_--) {
        solve();
    }
    return 0;
}