#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;

ll n;

void solve ()
{
    cin >> n;
    vector<ll> v(n + 1);
    vector<ll> s(n + 1);
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        sum += v[i];
        s[i] = s[i - 1] + v[i];
    }

    ll mn = 0;
    ll a = 0;
    for (ll i = 1; i <= n; i++) {
        ll t = (i + 1) * i - s[i];
        mn = min(mn, t);
        ll p = t - mn;
        a = max(a, p);
    }

    cout << sum + a << '\n';
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