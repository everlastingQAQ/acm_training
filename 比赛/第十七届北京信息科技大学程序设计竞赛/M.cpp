#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 1e9 + 7;
const ll inf = LLONG_MAX;

ld n;

void solve ()
{
    cin >> n;
    if (n < 60) {
        cout << 0 << '\n';
        return;
    }
    ld ans = min((double)(1.0 + (n - 60) * 0.1), 5.0);
    cout << fixed << setprecision(2) << ans << '\n';
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