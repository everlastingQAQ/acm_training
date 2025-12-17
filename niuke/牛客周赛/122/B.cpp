#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const ll MAXN = 1e7;
const ld eps = 1e-12;
const ll mod = 1e9 + 7;

ll n, m;

void solve ()
{
    cin >> n >> m;
    if (min(n, m) < 3) {
        cout << 1 << '\n';
    }else {
        n = (n + 1) / 2;
        m = (m + 1) / 2;
        cout << (n * m + 1) / 2 << '\n';
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