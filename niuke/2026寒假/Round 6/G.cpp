#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m, len;
    cin >> n >> m >> len;
    vector <int> v(n + 1), s(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        s[i] = s[i - 1] + v[i];
    }
    vector <int> a(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }

    int l = 0, r = len;
    int idx = 1;

    for (int i = 0; i <= m; i++) {
        l += a[i], r += a[i];
        while (idx <= n && s[idx] <= l) {
            idx++;
        }
        // cout << l << ' ' << r << ' ' << s[idx] << '\n';
        if (idx == n + 1) idx = n;
        if (l < s[idx] && r > s[idx]) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
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

/*
  /\_/\
 (= ._.)
 / >  \>
*/