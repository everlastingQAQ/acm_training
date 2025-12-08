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
    vector <ll> v(n + 1);
    vector <ll> d(n + 1);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        d[i] = v[i] - v[i - 1];
        if (d[i] > 0) {
            ans += d[i];
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