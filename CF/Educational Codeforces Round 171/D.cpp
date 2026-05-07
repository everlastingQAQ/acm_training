#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
	int n;
    cin >> n;
    vector <i64> v(n + 1), s(n + 1), ss(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        s[i] = s[i - 1] + v[i];
        ss[i] = ss[i - 1] + s[i];
    }

    vector <i64> sum(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i++) {
        i64 len = n - i + 1;
        sum[i] = ss[n] - ss[i - 1] - len * s[i - 1];
        pre[i] = pre[i - 1] + sum[i];
    }

    auto calp = [&] (i64 x) -> array <i64, 2> {

        auto check = [&] (i64 t) -> bool {
            i64 sum = t * (2LL * n - t + 1) / 2;
            return sum >= x;
        };

        i64 l = 1, r = n;
        while (l <= r) {
            i64 mid = (l + r) >> 1;
            if (check(mid)) {
                r = mid - 1;
            }else {
                l = mid + 1;
            }
        }
 
        i64 aa = l;
        i64 s1 = (aa - 1) * (2 * n - (aa - 1) + 1) / 2;
        i64 bb = x - s1;
        return {aa, bb};
    };  

    auto cals1 = [&] (i64 x, i64 y) -> i64 {
        i64 t = x + y - 1;
        i64 len = n - t + 1;
        i64 res = ss[n] - ss[t - 1] - len * s[x - 1];
        return res;
    };

    auto cals2 = [&] (i64 x, i64 y) -> i64 {
        i64 t = x + y - 1;
        i64 res = ss[t] - ss[x - 1] - y * s[x - 1];
        return res;
    };

    int q;
    cin >> q;
    while (q--) {
        i64 l, r;
        cin >> l >> r;
        auto [l1, l2] = calp(l);
        auto [r1, r2] = calp(r);
        i64 ans = 0;
        if (l1 == r1) {
            ans = cals2(l1, r2) - cals2(l1, l2 - 1);
        }else {
            if (r1 > l1 + 1) {
                ans += pre[r1 - 1] - pre[l1];
            }
            ans += cals1(l1, l2);
            ans += cals2(r1, r2);
        }
        cout << ans << '\n';
    }
} 

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}