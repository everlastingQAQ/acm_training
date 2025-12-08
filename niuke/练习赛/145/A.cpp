#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
ll n, m, x;

void solve ()
{
    cin >> n >> m >> x;
    
    ll ans = 0;
    vector <ll> v(m);
    ll sum = 0;
    ll p = 0;
    for (int i = 0; i < n; i++) {
        ll t;
        for (int j = 0; j < m; j++) {
            if (i == 0) {
                cin >> v[j];
                sum += v[j];
            }else {
                cin >> t;
                if (t > v[j]) {
                    p -= t - v[j];
                    v[j] = t;
                }
            }
        }
        if (i == 0) {
            p = x - sum;
        }
        //cout << p << '\n';
        if (p < 0) {
            cout << ans << '\n';
            return;
        }
        ans++;
    }

    cout << ans << '\n';
    return;
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