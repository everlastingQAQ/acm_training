#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <int> s(n + 1), p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    
    vector <int> pre(n + 1);
    for (int i = 1; i <= n; i++) {
        if (s[i] < p[i]) pre[i] = 1;
        else pre[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        pre[i] += pre[i - 1];
    }

    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        int t = pre[r] - pre[l - 1];
        cout << (t == 0 ? "Yes\n" : "No\n");
    }
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