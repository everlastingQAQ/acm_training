#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ld, ld>;

#define fi first
#define se second
const int MAXN = 6e7;
const double eps = 1e-12;
const ll mod = 1e9 + 7;

void solve ()
{
    auto findx = [&] (ll x) -> ll {
        if(x < 2) return 0;
        return (int)ceil((sqrt(8.0*(x-1)+1)-1)/2.0);
    };

    ll n;
    cin >> n;
    cout << findx(n);
    cout << "test" << '\n';
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