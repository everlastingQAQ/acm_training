#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<string, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-12;
// const ll mod = 998244353;

void init() 
{

}
    
ll qpow (ll a, ll b, ll m)
{
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve ()
{
    ll a, b, m; cin >> a >> b >> m;
    vector <ll> va(m, 0);
    vector <ll> vb(m, 0);
    for (int i = 0; i < m; i++) {
        va[qpow(i, a, m) % m]++;
        vb[qpow(i, b, m) % m]++;
    }   

    ll ans = 0;
    for (int i = 0; i < m; i++) {
        ans += va[i] * vb[i];
    }

    cout << ans << '\n';
}   

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    init();
    while (_--) {
        solve();
    }
    return 0;
}