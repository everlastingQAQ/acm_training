#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <int> vis(n + 1);
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        vis[t] = true;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cout << i << '\n';
            return;
        }
    }
    cout << -1 << '\n';
} 

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 