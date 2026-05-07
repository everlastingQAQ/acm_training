#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, q;
    cin >> n >> q;
    vector <array <int, 2> > v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i][0];
        v[i][1] = i;
    }
    sort(v.begin() + 1, v.end());
    vector <int> a;
    a.push_back(0);
    for (int i = 1; i <= n; i++) {
        a.push_back(v[i][1]);
    }

    vector <int> vis(n + 1, 0);

    while (q--) {
        vector <int> b;
        int k;
        cin >> k;
        for (int i = 1; i <= k; i++) {
            int t;
            cin >> t;
            vis[t] = true;
            b.push_back(t);
        }
        int tt = 1;
        while (tt < n && vis[a[tt]]) {
            tt++;
        }
        cout << v[tt][0] << '\n';
        for (auto x : b) {
            vis[x] = false;
        }
    }
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