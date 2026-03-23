#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    i64 l, r;
    cin >> l >> r;
    i64 tt = 1;
    for (int i = 1; i < n; i++) {
        tt *= 10;
    }
    // cout << tt << '\n';

    auto cal = [&] (i64 x, i64 t) -> bool {
        for (int i = 1; i <= n; i++) {
            i64 y = (x - x % t) / t;
            if (y % i != 0) return false;
            t /= 10;
        }
        return true;
    };

    auto cal1 = [&] (i64 x) -> int {
        int cnt = 0;
        while (x > 0) {
            x /= 10;
            cnt++;
        }
        return cnt;
    };

    // cout << cal1(10) << '\n';

    bool ok = false;
    for (i64 i = max(tt, l); i <= min(r, tt * 10 - 1); i++) {
        if (cal(i, tt)) {
            ok = true;
            cout << i << '\n';
        }
    }

    if (!ok) {
        cout << "No Solution";
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