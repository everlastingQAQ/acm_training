#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;

ll n, ans = 0;
vector <vector <ll> > v(6);

void dfs (ll x, ll cnt)
{
    if (cnt == n) {
        ans++;
        return;
    }

    for (auto k : v[x]) {
        dfs(k, cnt + 1);
    }

}

void solve ()
{
    cin >> n;
    for (int i = 1; i <= 5; i++) {
        ll t;
        cin >> t;
        for (int j = 1; j <= t; j++) {
            ll o;
            cin >> o;
            v[i].emplace_back(o);
        }
    }

    for (int i = 1; i <= 5; i++) {
        dfs(i, 1);
        //cout << ans << '\n';
    }

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