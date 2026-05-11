#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-12;
const int mod = 998244353;

void solve ()
{
    int n; cin >> n;
    vector <vector <int> > e(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    if (n == 2) {
        cout << 0 << '\n';
        return;
    }

    int sum = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        sum += (e[i].size() == 1);
        int cnt = 0;
        for (int x : e[i]) {
            cnt += (e[x].size() == 1);
        }
        ans = max(ans, cnt);
    }
    cout << sum - ans << '\n';
}   
    
signed main ()
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