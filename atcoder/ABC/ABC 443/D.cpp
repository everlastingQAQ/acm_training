#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n; cin >> n;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];

    vector <int> pre(n + 1), suf(n + 1);

    pre[1] = v[1];
    for (int i = 2; i <= n; i++) {
        pre[i] = min(v[i], pre[i - 1] + 1);
    }

    suf[n] = v[n];
    for (int i = n - 1; i >= 1; i--) {
        suf[i] = min(v[i], suf[i + 1] + 1);
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        ans += v[i] - min(pre[i], suf[i]);
    }

    cout << ans << '\n';
}   
    
int32_t main ()
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