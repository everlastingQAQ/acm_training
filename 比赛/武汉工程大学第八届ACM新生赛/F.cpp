#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;

ll n, q, k;

void solve ()
{
    cin >> n >> q >> k;
    vector <ll> v(n + 1, 0);
    vector <ll> s(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        s[i] = s[i - 1] + v[i];
    }

    ll l, r;
    for (int i = 0; i < q; i++) {
        cin >> l >> r;
        ll t = s[r] - s[l - 1];
        
    }
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