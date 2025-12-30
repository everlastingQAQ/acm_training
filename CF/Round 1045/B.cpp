#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int MAXN = 6e7;
const double eps = 1e-12;
const ll mod = 998244353;

void solve ()
{
    ll n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) {
        ll t; cin >> t;
        ll tt = (t % (k + 1)) * k;
        cout << tt + t << " \n"[i == n - 1];
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