#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(n + 1), d1(n + 1), d2(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        d1[i] = v[i] - v[i - 1];
        if (i > 1) d2[i] = v[i] - v[i - 2];
    }
    int c0 = 0, c1 = 0;
    for (int i = 2; i <= n; i++) {
        c0 += (d1[i] >= 0);
        c1 += (d1[i] <= 0);
    }
    if (c0 == n - 1 || c1 == n - 1) {
        cout << "YES\n";
        return;
    }
    for (int i = 2; i <= n - 1; i++) {
        int cc0 = c0, cc1 = c1;
        cc0 -= (d1[i] >= 0);
        cc1 -= (d1[i] <= 0);
        cc0 -= (d1[i + 1] >= 0);
        cc1 -= (d1[i + 1] <= 0);
        cc0 += (d2[i + 1] >= 0);
        cc1 += (d2[i + 1] <= 0);
        if (cc0 == n - 2 || cc1 == n - 2) {
            cout << "YES\n";
            return;
        }
    }
    
    if (is_sorted(v.begin() + 2, v.end(), less<>()) || is_sorted(v.begin() + 2, v.end(), greater<>())) {
        cout << "YES\n";
        return;
    }
    if (is_sorted(v.begin() + 1, v.begin() + n, less<>()) || is_sorted(v.begin() + 1, v.begin() + n, greater<>())) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
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