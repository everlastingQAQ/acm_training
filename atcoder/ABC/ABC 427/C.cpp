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

ll n, m;
ll gp[100];
ll u[100], v[100];
ll ans = inf;

void dfs (ll p)
{
    if (p > n) {
        ll cnt = 0;
        for (int i = 0; i < m; i++) {
            if (gp[u[i]] == gp[v[i]]) {
                cnt++;
            }
        }
        ans = min(ans, cnt);
        return;
    }

    gp[p] = 1;
    dfs(p + 1);
    gp[p] = 2;
    dfs(p + 1);
}

void solve ()//dfs
{
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u[i] >> v[i];
    }
    dfs(1);
    cout << ans << '\n';
}

void solve2 ()//二进制枚举
{
    cin >> n >> m;
    ll uu[100], vv[100];
    for (int i = 0; i < m; i++) {
        cin >> uu[i] >> vv[i];
    }
    ll ans2 = inf;

    ll gpp[100];
    for (int sta = 0; sta < (1 << n); sta++) {
        for (int i = 1; i <= n; i++) {
            gpp[i] = ((sta >> (i - 1)) & 1);
        }
        ll cntt = 0;
        for (int j = 0; j < m; j++) {
            if (gpp[uu[j]] == gpp[vv[j]]) {
                cntt++;
            }
        }
        ans2 = min(ans2, cntt);
    }
    cout << ans2 << '\n';
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    //cin >> _;
    while (_--) {
        solve2();
    }
    return 0;
}