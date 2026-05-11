#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 1e9 + 7;
const ll inf = LLONG_MAX;

ll n, rk, ck, rd, cd;

void solve ()
{
    cin >> n >> rk >> ck >> rd >> cd;
    ll ans = 0;
    if (rk > rd) {
        ans = max(ans, n - rd);
    }else if (rk < rd) {
        ans = max(ans, rd);
    }
    if (ck > cd) {
        ans = max(ans, n - cd);
    }else if (ck < cd) {
        ans = max(ans, cd);
    }

    cout << ans << '\n';
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