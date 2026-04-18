#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <vector <int> > e(n + 1);
    vector <int> ind(n + 1);
    for (int i = 1; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(u);
        e[v].push_back(v);
        ind[u]++;
        ind[v]++;
    }
    sort(ind.begin() + 1, ind.end(), greater<>());
    if (ind[1] + ind[2] >= m) {
        cout << "YES\n";
    }else {
        cout << "NO\n";
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