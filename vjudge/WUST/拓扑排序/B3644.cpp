#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    i64 n; cin >> n;
    vector <vector <i64> > e(n + 1);
    vector <i64> ind(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        i64 t;
        while (cin >> t) {
            if (t == 0) break;
            e[i].push_back(t);
            ind[t]++;
        }
    }

    queue <i64> q;
    for (int i = 1; i <= n; i++) {
        if (ind[i] == 0) q.push(i);
    }

    vector <i64> ans(n + 1);
    i64 pos = 1;
    while (!q.empty()) {
        i64 u = q.front();
        q.pop();
        ans[pos++] = u;
        for (i64 v : e[u]) {
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