#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{   
    int n;
    cin >> n;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    vector <int> pre(n + 1), preans(n + 1);
    pre[0] = -1e11;
    preans[0] = -1e11;
    for (int i = 1; i <= n; i++) {
        pre[i] = max(pre[i - 1] + v[i], v[i]);
        preans[i] = max(preans[i - 1], pre[i]);
    }
    vector <int> suf(n + 2), sufans(n + 2);
    suf[n + 1] = -1e11;
    sufans[n + 1] = -1e11;
    for (int i = n; i >= 1; i--) {
        suf[i] = max(suf[i + 1] + v[i], v[i]);
        sufans[i] = max(sufans[i + 1], suf[i]);
    }

    vector <int> ans(n + 1);
    for (int i = 2; i <= n - 1; i++) {
        ans[i] = preans[i - 1] + sufans[i + 1];
    }

    cout << ranges::max(ans | views::drop(2) | views::take(n - 2)) << '\n';
}   
    
int32_t main ()
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