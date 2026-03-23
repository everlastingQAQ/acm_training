#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    i64 v;
    cin >> v;
    vector <double> a(n + 1);
    i64 cur = 0;
    for (int i = 2; i <= n; i++) {
        i64 t;
        cin >> t;
        cur += t;
        a[i] = (double)(1.0 * cur / v);
    }
    bool ok = false;
    for (int i = 2; i <= n; i++) {
        i64 t;
        cin >> t;
        if (t > a[i]) {
            ok = true;
            cout << i << ' ';
        }
    }
    if (!ok) {
        cout << -1;
    }
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