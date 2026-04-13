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

    auto func = [&] (ll x, auto self) -> ll {
        if (x < 1) {
            return 0;
        }else if (x & 1) {
            return x + self(x - 2, self);
        }else {
            return self(x - 2, self) - x;
        }
    };

    ll ans = func(n, func);

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