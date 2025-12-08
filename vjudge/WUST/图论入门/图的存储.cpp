#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;

ll n, m;

void solve ()
{
    cin >> n >> m;

    vector <vector<ll> > e(n + 1);
    vector <vector<ll> > ans1(n + 1, vector <ll> (n + 1));

    for (int i = 1; i <= m; i++) {
        ll u, v;
        cin >> u >> v;
        ans1[u][v] = 1;
        ans1[v][u] = 1;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << ans1[i][j] << ' ';
        }
        cout << '\n';
    }

    for (int i = 1; i <= n; i++) {
        cout << e[i].size() << ' ';
        sort(e[i].begin(), e[i].end());
        for (auto x : e[i]) {
            cout << x << ' ';
        }
        cout << '\n';
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