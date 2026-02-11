#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 998244353;

ll m, n;

void solve ()
{
    cin >> m >> n;
    vector <ll> p(n + 1);
    vector <ll> t(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i] >> t[i];
    }

    vector <ll> f(m + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = t[i]; j <= m; j++) {
            f[j] = max(f[j], f[j - t[i]] + p[i]);
        }
    }

    cout << f[m] << '\n';
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