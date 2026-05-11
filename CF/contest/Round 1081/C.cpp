#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    i64 n, h, k;
    cin >> n >> h >> k;
    vector <i64> v(n + 6), pre(n + 6), premn(n + 6, 0), sufmx(n + 6, 0);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        pre[i] = pre[i - 1] + v[i];
    }
    sufmx[n] = v[n];
    for (int i = n - 1; i >= 1; i--) {
        sufmx[i] = max(v[i], sufmx[i + 1]);
    }

    premn[1] = v[1];
    for (int i = 2; i <= n; i++) {
        premn[i] = min(v[i], premn[i - 1]);
    }

    i64 t = h / pre[n];
    i64 p = h % pre[n];
    i64 ans = t * (n + k);

    if (p == 0) {
        cout << ans - k << '\n';
        return;
    }

    vector <i64> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        if (i == n) {
            ans += n;
            break;
        }

        dp[i] = pre[i] + max(0LL, -premn[i] + sufmx[i + 1]); 
    
        if (dp[i] >= p) {
            ans += i;
            break;
        }
    }

    cout << ans << '\n';
}   
    
int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 

/*
  /\_/\
 (= ._.)
 / >  \>
*/