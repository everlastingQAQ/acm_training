#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    sort(v.begin() + 1, v.end());
    int x;
    if (n & 1) {
        x = v[n / 2 + 1];
    }else {
        x = (v[n / 2 + 1] + v[n / 2]) >> 1;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += abs(v[i] - x);
    }
    cout << ans << '\n';
}   
    
int32_t main ()
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