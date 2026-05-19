#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, q;
    cin >> n >> q;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    vector <int> d(n + 10);
    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        d[l]++;
        d[r + 1]--;
    }
    vector <int> dd(n + 1);
    for (int i = 1; i <= n; i++) {
        dd[i] = dd[i - 1] + d[i];
    }
    for (int i = 1; i <= n; i++) {
        cout << max(0LL, v[i] - dd[i]) << ' ';
    }
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