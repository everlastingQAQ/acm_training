#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const ll MAXN = 1e7;
const ld eps = 1e-12;
const ll mod = 1e9 + 7;

ll n;

void solve ()
{
    cin >> n;
    ll m = sqrtl(2 * n);

    ll ans = 0;
    for (int i = 1; i <= m; i++) {
        if ((2 * n) % i == 0 && (2 * n) / i - i + 1 > 0 && ((2 * n) / i - i + 1) % 2 == 0) {
            ans++;
        }
    }
    cout << ans << '\n';
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