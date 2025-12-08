#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
ll n, m, k, q;

void solve ()
{
    cin >> n >> m >> k;

    vector <ll> ans(n + 1);

    for (int u = 1; u <= n; u++) {
        vector <ll> v(m + 1);
        vector <ll> a(k + 1, 0);
        ll t = 1;
        for (int i = 1; i <= m; i++) {
            cin >> v[i];
            if (i == m) {
                if (v[m] != v[m - 1]) {
                    a[v[m]] = max(a[v[m]], 1LL);
                }else {
                    a[v[i]] = max(a[v[i]], t);
                }
                break;
            }
            if (v[i + 1] == v[i]) {
                t++;
                a[v[i]] = max(a[v[i]], t);
            }else {
                a[v[i]] = max(a[v[i]], t);
                t = 1;
            }
        }
        auto it = max_element(a.begin() + 1, a.end());
        auto p = lower_bound(a.begin() + 1, a.end(), *it) - a.begin();
        ans[u] = p;
    }

    cin >> q;
    ll o;
    for (int i = 0; i < q; i++) {
        cin >> o;
        cout << ans[o] << '\n';
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