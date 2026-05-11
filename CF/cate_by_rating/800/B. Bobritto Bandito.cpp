#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 1e6 + 5;
const double eps = 1e-5;
const ll mod = 998244353;
ll n, m, l, r;

void solve ()
{
    cin >> n >> m >> l >> r;

    ll t = n - m;

    if (l + t <= 0) {
        cout << l + t << ' ' << r << endl;
    }else if (r - t >= 0) {
        cout << l << ' ' << r - t << endl;
    }else {
        ll p;
        for (ll i = 1; i < t; i++) {
            if (l + (t - i) <= 0 && r - i >= 0) {
                p = i;  
            }
        }
        cout << l + (t - p) << ' ' << r - p << endl; 
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