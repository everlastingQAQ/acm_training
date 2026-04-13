#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;

ll m;

void solve ()
{
    cin >> m;
    ll l = 1, r = 1;
    ll ans = 0;

    while (r * r <= m) {
        if (m % r != 0) {
            r++;
        }else {
            if (m % r == 0 && m % (r + 1) == 0) {
                ans++;
            }
            r++;
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