#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

void solve ()
{
    int n; cin >> n;
    int cnt = 0;
    int t = 0;
    for (int i = 1; i <= n; i++) {
        int temp; cin >> temp;
        if (temp & 1) {
            t += cnt * (cnt + 1) / 2;
            cnt = 0;
        }else {
            cnt++;
        }
    }
    t += cnt * (cnt + 1) / 2;
    cout << n * (n + 1) / 2 - t << '\n';
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