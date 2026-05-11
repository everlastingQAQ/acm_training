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

    auto check = [&] (int md) -> bool {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (v[i] >= md) continue;
            int t = md - v[i];
            int cur = t / i;
            if (i * cur != t) cur++;
            cnt += cur;
            if (cnt > k) return false;
        }
        return cnt <= k;
    };

    int l = 1, r = 2e18;
    while (l <= r) {
        int mid = l + ((r - l) >> 1);
        if (check(mid)) {
            l = mid + 1;
        }else {
            r = mid - 1;
        }
    }
    cout << r << '\n';
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