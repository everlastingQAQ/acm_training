#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    int mx = -1;
    int sum = 0;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        mx = max(v[i], mx);
        sum += v[i];
    }
    if (mx >= sum - mx) {
        cout << 2 * mx << '\n';
    }else {
        cout << sum << '\n';
    }
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