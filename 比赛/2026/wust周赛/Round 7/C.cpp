#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, k;
    cin >> n >> k;
    vector <int> v(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    vector <int> a(n + 1);
    int pre = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (pre + (k - 1) * v[i] <= 0) {
            pre = 0;
        }else {
            pre += (k - 1) * v[i];
        }
        ans = max(ans, sum + pre);
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