#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 998244353;

ll n, k, ans = 0;

void dfs (ll x, ll sum, ll cnt)
{
    if (cnt == k) {
        if (sum == n) {
            ans++;
        }
        return;
    }
    for (int i = x; i <= n; i++) {
        if (i + sum > n) return;
        dfs(i, sum + i, cnt + 1);
    }
}

void solve ()
{
    cin >> n >> k;
    dfs(1, 0, 0);
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
