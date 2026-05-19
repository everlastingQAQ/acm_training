#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(n + 1);
    int ans = 0;
    int c1 = 0;
    int x = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        if (v[i] != 1) ans += v[i];
        else c1++;
        if (v[i] >= 4) x += v[i] / 2 - 1;
    }
    if (c1 == n - 1) x++; 
    int ext = min(c1, x);
    ans += ext;
    cout << (ans < 3 ? 0 : ans) << '\n';
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