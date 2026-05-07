#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
	int n;
    cin >> n;
    vector <i64> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    i64 mx = v[1];
    vector <i64> a(n + 1);
    a[1] = mx;
    i64 ans = 0;
    for (int i = 2; i <= n; i++) {
        a[i] = max(v[i], mx);
        mx = max(mx, a[i]);
        ans += a[i] - v[i];
    }
    
    i64 a1 = 0;
    vector <i64> cnt(n + 1);
    for (int i = 1; i <= n; i++) {
        cnt[i] = a[i] - v[i];
        a1 = max(a1, cnt[i]);
    }

    cout << ans + a1 << '\n';
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