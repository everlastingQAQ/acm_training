#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, q; cin >> n >> q;
    vector <int> s(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int l, r, diff; cin >> l >> r >> diff;
        s[l] += diff;   
        s[r] -= diff;
    }
}   
    
signed main ()
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