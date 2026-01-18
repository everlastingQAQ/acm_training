#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

void solve ()
{
    int n, a1, mod; cin >> n >> a1 >> mod;
    vector <int> v(n + 1), b(n + 1);
    v[1] = a1;
    for (int i = 2; i <= n; i++) {
        v[i] = (v[i - 1] + 7 * i) % mod;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            b[j] += v[i];
        }
    }

    int ans = b[1];
    for (int i = 2; i <= n; i++) {
        ans ^= b[i];
    }

    cout << ans << '\n';

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