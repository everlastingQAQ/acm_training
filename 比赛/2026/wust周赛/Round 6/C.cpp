#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    int sum = 0;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    int p = sum / n;
    sort(v.begin() + 1, v.end());
    auto cal = [&] (int p) -> int {
        int res = 0;
        for (int i = 1; i <= n; i++) {
            res += abs(v[i] - p);
        }
        return res;
    };
    if (n & 1) {
        int p = v[n / 2 + 1];
        cout << cal(p) << '\n';
    }else {
        int p1 = v[n / 2], p2 = v[n / 2 + 1];
        int p = ((p1 + p2) >> 1);
        int ans = 1e18;
        for (int i = -3; i <= 3; i++) {
            ans = min(ans, cal(p + i));
        }
        cout << ans << '\n';
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