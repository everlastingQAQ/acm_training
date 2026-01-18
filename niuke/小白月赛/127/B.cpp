#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

void solve ()
{
    int n, k; cin >> n >> k;
    vector <int> v(k + 1);
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        t %= k;
        v[t]++;
    }

    for (int i = 0; i < k; i++) {
        if (v[i] & 1) {
            cout << "No" << '\n';
            return;
        }
    }

    cout << "Yes" << '\n';
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