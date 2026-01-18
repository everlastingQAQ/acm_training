#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

void solve ()
{
    int n, k; cin >> n >> k;
    vector <int> v(n);
    int sum = 0;
    for (int &x : v) cin >> x, sum ^= x;

    if (sum == 0 || *max_element(v.begin(), v.end()) <= k && k != 0) {
        cout << "NO" << '\n';
    }else {
        cout << "YES" << '\n';
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