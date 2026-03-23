#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    i64 r, t;
    cin >> r >> t;
    vector <i64> v(n);
    for (i64 &x : v) {
        cin >> x;
    }

    for (int i = 0; i < n; i++) {
        cout << min(t / v[i], r) << " \n"[i == n - 1];
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