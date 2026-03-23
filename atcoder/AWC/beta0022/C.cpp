#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, m, k, t;
    cin >> n >> m >> k >> t;
    vector <int> v(n + 1, 0);
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        v[x]++;
    }
    for (int i = 1; i <= n; i++) {
        v[i] += v[i - 1];
    }

    while (k--) {
        int l, r;
        cin >> l >> r;
        cout << (v[r] - v[l - 1] >= t ? "YES\n" : "NO\n");
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