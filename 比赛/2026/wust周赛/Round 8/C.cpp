#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m;
    cin >> n >> m;
    while (n > 2 && m) {
        int cur = sqrtl(n);
        if (cur * cur != n) cur++;
        m--;
        n = cur;
    }
    cout << n - m << '\n';
}   

int32_t main ()
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