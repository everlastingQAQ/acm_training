#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n; cin >> n;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    int sum = accumulate(v.begin() + 1, v.end(), 0LL);
    if (sum % n == 0) {
        int t = sum / n;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += max(0LL, v[i] - t);
        }
        cout << ans << '\n';
        return;
    }

    sort(v.begin() + 1, v.end());
    int ans = 2e18;

    auto cal = [&] (int ave, int pos) -> int {
        int cur = 0;
        for (int i = 1; i <= n; i++) {
            if (i == pos) cur += max(0LL, v[i] - (sum - (n - 1) * ave));
            else cur += max(0LL, v[i] - ave);
        }
        return cur;
    };

    int t1 = (sum - v[n]) / (n - 1);
    int t2 = (sum - v[1]) / (n - 1);

    for (int i = -2; i <= 2; i++) {
        ans = min(ans, cal(t1 + i, n));
        ans = min(ans, cal(t1 + i, 1));
        ans = min(ans, cal(t2 + i, n));
        ans = min(ans, cal(t2 + i, 1));
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