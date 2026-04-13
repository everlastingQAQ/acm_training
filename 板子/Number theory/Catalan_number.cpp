#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n; cin >> n;
    vector <i64> f(n + 1);
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1] * (4 * i - 2) / (i + 1);
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