#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

void solve ()
{
    int n, x; cin >> n >> x;
    vector <int> v(n);
    int sum = 0;
    for (int &t : v) cin >> t, sum += t;

    if (x >= n) {
        cout << sum << '\n';
        return;
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