#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <i64> a(n + 1);
    i64 ave = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ave += a[i];
    }

    ave /= n;

    vector <i64> v(n + 1);
    for (int i = 1; i <= n; i++) {
        v[i] = v[i - 1] - ave + a[i];
    }

    sort(v.begin() + 1, v.end());

    i64 t = v[n / 2 + 1];
    
    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += abs(t - v[i]);
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