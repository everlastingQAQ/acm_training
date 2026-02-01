#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n; cin >> n;
    vector <int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    int t = a[1];
    for (int i = 2; i <= n; i++) {
        t = gcd(a[i], t);
    }

    if (t != b[1]) {
        cout << "NO" << '\n';
        return;
    }

    for (int i = 1; i < n; i++) {
        if (a[i] % a[i + 1] != 0) {
            cout << "NO" << '\n';
            return;
        }
    }

    for (int i = n - 1; i >= 1; i--) {
        if (b[i + 1] % b[i] != 0) {
            cout << "NO" << '\n';
            return;
        }
    }

    for (int i = 1; i < n; i++) {
        if (gcd(a[i], b[i + 1]) != t) {
            cout << "NO" << '\n';
            return;
        }
    }

    cout << "YES" << '\n';
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