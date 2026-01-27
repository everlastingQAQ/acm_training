#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 998244353;

ll n, l, r, ans = 0;
ll e[40];

void dfs (ll pos, ll sum)
{
    if (sum > r) {
        return;
    }
    if (sum >= l && sum <= r) {
        ans++;
    }

    for (int i = pos; i < n; i++) {
        if (e[i] + sum > r) return;
        dfs(i + 1, sum + e[i]);
    }
}

void solve ()
{
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        cin >> e[i];
    }
    sort(e, e + n);
    dfs(0, 0);
    cout << ans << '\n';
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