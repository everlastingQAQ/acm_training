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
    sort(v.begin() + 1, v.end(), greater<>());
    int ans = 0;
    int cur = 0;
    for (int i = 2; i <= n; i += 2) {
        int diff = v[i - 1] - v[i];
        if (diff + cur <= k) {
            v[i] += diff;
            cur += diff;
        }else {
            v[i] += k - cur;
            cur = k;
        }
        if (cur == k) {
            break;
        }
    }
    for (int i = 2; i <= n; i += 2) {
        ans += v[i - 1] - v[i];
    }
    if (n & 1) {
        ans += v[n];
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