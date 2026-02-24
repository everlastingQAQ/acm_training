#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, k;
    cin >> n >> k;
    i64 m;
    cin >> m;
    vector <i64> v(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        pre[i] = pre[i - 1] + v[i];
    }

    i64 ans = 0;
    for (int i = k; i <= n; i++) {
        int pos = upper_bound(pre.begin(), pre.begin() + 1 + i - k, pre[i] - m) - pre.begin();
        ans += pos;
    }

    cout << ans << '\n';
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

/*
  /\_/\
 (= ._.)
 / >  \>
*/