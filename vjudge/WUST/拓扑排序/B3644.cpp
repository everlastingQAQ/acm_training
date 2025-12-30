#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int MAXN = 6e7;
const double eps = 1e-12;
const ll mod = 998244353;

void solve ()
{
    ll n; cin >> n;
    vector <vector <ll> > e(n + 1);
    vector <ll> ind(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        ll t;
        while (cin >> t) {
            if (t == 0) break;
            e[i].push_back(t);
            ind[t]++;
        }
    }

    queue <ll> q;
    for (int i = 1; i <= n; i++) {
        if (ind[i] == 0) q.push(i);
    }

    vector <ll> ans(n + 1);
    ll pos = 1;
    while (!q.empty()) {
        ll u = q.front();
        q.pop();
        ans[pos++] = u;

        for (ll v : e[u]) {
            if (--ind[v] == 0) q.push(v);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }

}
 
int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}