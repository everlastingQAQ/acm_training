#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
ll n;

void solve ()
{
    cin >> n;
    vector <ll> a(n + 1);
    vector <ll> sum(n + 1, 0);

    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = a[i] + sum[i - 1];
    }

    for (ll i = 1; i <= n; i++) {
        sum[i] = log2(sum[i] + 1) * 
    }

    ll ans = 0;
    for (ll i = 1; i <= n; i++) {
        ans += (i)
    }
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