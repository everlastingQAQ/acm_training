#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int l, r;
    cin >> l >> r;
    if (r - l <= 10) {
        int ans = 0;
        auto cal = [&] (int x) -> int {
            string s = to_string(x);
            int mx = 0;
            for (auto c : s) {
                int t = c - '0';
                mx = max(mx, t);
            }
            return mx;
        };
        set <string> v;
        int mx = -1;
        for (int i = l; i <= r; i++) {
            if (cal(i) > mx) {
                mx = max(cal(i), mx);
                v.clear();
                v.insert(to_string(i));
            }else if (cal(i) == mx) {
                v.insert(to_string(i));
            }
        }
        cout << mx << ' ' << *v.begin() << '\n';
    }else {
        cout << 9 << ' ';
        int t = l - l % 10;
        t += 9;
        int ans = t;
        string s = to_string(t);
        bool ok = false;
        string sss = to_string(l);

        for (auto c : sss) {
            if (c == '9') {
                ok = true;
                break;
            }
        }
        if (ok) {
            ans = l;
        }

        int len = s.size();
        string ss = "1" + string(len - 1, '0') + "9";
        int x = stoll(ss);
        int cur = x - x % 10;
        while (x <= r) {
            ans = x;
            x -= cur;
            cur *= 10;
            x += cur;
        }
        cout << ans << '\n';
    }
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