#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <int> c(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> c[i];
    }

    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        if (c[a] > 0) {
            int t = min(b, c[a]);
            ans += t;
            c[a] -= t;
        }else {
            continue;
        }
    }

    cout << ans << '\n';
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