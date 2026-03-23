#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    i64 n, q; cin >> n >> q;
    vector <i64> v(n + 1);
    for (i64 i = 1; i <= n; i++) cin >> v[i];
    i64 t = log2(n);
    vector <vector <i64> > stmx(n + 1, vector <i64> (30));
    vector <vector <i64> > stmn(n + 1, vector <i64> (30));
    for (i64 i = 1; i <= n; i++) stmx[i][0] = v[i], stmn[i][0] = v[i];
    for (i64 j = 1; j <= t; j++) {
        for (i64 i = 1; i <= n - (1LL << j) + 1; i++) {
            stmx[i][j] = max(stmx[i][j - 1], stmx[i + (1LL << (j - 1))][j - 1]);
            stmn[i][j] = min(stmn[i][j - 1], stmn[i + (1LL << (j - 1))][j - 1]);
        }
    }

    while (q--) {
        i64 l, r; cin >> l >> r;
        i64 len = log2(r - l + 1);
        i64 mx = max(stmx[l][len], stmx[r - (1LL << len) + 1][len]);
        i64 mn = min(stmn[l][len], stmn[r - (1LL << len) + 1][len]);
        cout << mx - mn << '\n';
    }
}   
 
i64 main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    i64 _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}