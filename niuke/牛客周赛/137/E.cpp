#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <i64> v(n + 1), a(n + 1);
    i64 mx = -1e9, mn = 1e9;
    i64 ans = -1e9;
    for (int i = 1; i <= n; i++) {
    	cin >> v[i];
        a[i] = v[i] - i;
        mn = min(mn, a[i]);
        ans = max(ans, a[i] - mn);
    }   
    for (int i = 1; i <= n; i++) {
        a[i] = v[i] + i;
        mx = max(mx, a[i]);
        ans = max(ans, mx - a[i]);
    }
    cout << ans << '\n';
} 

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 