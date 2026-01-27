#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, q; cin >> n >> q;
    vector <int> a(n + 1);
    vector <int> b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) {
        if (a[i] < b[i]) a[i] = b[i];
    }

    for (int i = n - 1; i >= 1; i--) {
        a[i] = max(a[i], a[i + 1]);
    }

    vector <int> s(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
    }

    while (q--) {
        int l, r; cin >> l >> r;
        cout << s[r] - s[l - 1] << " \n"[q == 0];
    }
}   
    
signed main ()
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