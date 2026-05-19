#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, k;
    cin >> n >> k;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    int ans = 0;
    int l = 1, r = 2;
    while (r <= n) {
        while (r <= n && 2 * v[r] > v[r - 1]) {
            r++;
        }
        int len = r - l;
        ans += max(0LL, len - k);
        l = r;
        r++;
    }
    cout << ans << '\n';
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