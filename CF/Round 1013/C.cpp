#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n; cin >> n;
    if (!(n & 1)) {
        cout << -1 << '\n';
        return;
    }

    vector <int> v(n + 1);
    int cur = 1;
    int idx = 1;
    while (idx <= n) {
        v[idx] = cur;
        idx++;
        cur += 2;
        if (cur > n) {
            cur -= n;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << v[i] << " \n"[i == n];
    }
}   
    
signed main ()
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