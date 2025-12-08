#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 998244353;
 
ll n, m;

void solve ()
{
    cin >> n >> m;
    vector <pi> v(m + 1, {0, 0});
    while (n--) {
        ll a, b;    
        cin >> a >> b;
        v[a].fi += b;
        v[a].se++;
    }
    for (int i = 1; i <= m; i++) {
        cout << fixed << setprecision(5) << 1.0 * v[i].fi / v[i].se << '\n';
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