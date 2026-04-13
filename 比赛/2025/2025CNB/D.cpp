#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const ll MAXN = 1e7;
const ld eps = 1e-12;
const ll mod = 1e9 + 7;

ll n, k;

void solve ()
{
    cin >> n >> k;
    vector <ll> v(n + 1);
    ll mx = 0;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        sum += v[i];
        mx = max(mx, v[i]);
    }

    ll t;
    if (sum % k == 0) {
        t = sum / k;
    }else {
        t = sum / k + 1;
    }

    cout << max(t, mx);
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