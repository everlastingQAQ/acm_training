#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <vector <int> > e(n + 1);
    vector <int> ind(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (e[i].size() <= 1) continue;
        for (auto j : e[i]) {
            if (e[j].size() <= 1) continue;
            int cnt0 = 0;
            for (auto x : e[i]) {
                if (cnt0 == 3) break;
                int cnt1 = 0;
                for (auto y : e[j]) {
                    if (cnt1 == 3) break;
                    if (i != j && x != y && i != y && x != j) {
                        cout << x << '\n';
                        cout << i << '\n';
                        cout << j << '\n';
                        cout << y << '\n';
                        return;
                    }
                    cnt1++;
                }
                cnt0++;
            }
        }
    }

    cout << -1 << '\n';
} 
    
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 