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

ll n;

void solve ()
{
    cin >> n;
    if (n == 2 || n == 3 || n == 4) {
        cout << -1 << '\n';
        return;
    }

    cout << (n - 2) * 2 << '\n';

    for (int i = 2; i <= n; i++) {
        cout << 1 << ' ' << i << '\n';
    }

    cout << 2 << ' ' << 3 << '\n';

    for (int i = 4; i < n; i++) {
        cout << i << ' ' << i + 1 << '\n';
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