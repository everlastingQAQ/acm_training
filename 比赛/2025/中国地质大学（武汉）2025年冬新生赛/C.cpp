#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;

ll n, m;

void solve ()
{
    cin >> n;
    vector <ll> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    cin >> m;
    vector <ll> d(n + 2, 0);
    ll a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        d[a]++;
        d[b + 1]--;
    }
    
    vector <ll> c(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        c[i] = c[i - 1] + d[i];
        //cout << d[i] << '\n';
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        
        if (c[i] % 2 == 0) {
            ans += v[i];
        }else {
            ans -= v[i];
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