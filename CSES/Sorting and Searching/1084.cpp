#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector <int> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }

    sort(a.begin() + 1, a.end());
    sort(b.begin() + 1, b.end());

    int la = 1, lb = 1;
    int ans = 0;
    while (la <= n && lb <= m) {
        while (lb <= m && b[lb] < a[la] - k) {
            lb++;
        }
        // cout << la << ' ' << a[la] << ' ' << lb << ' ' << b[lb] << '\n'; 
        if (lb == m + 1) break;
        if (b[lb] <= a[la] + k) ans++, lb++;
        la++;
    }
    cout << ans << '\n';
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