#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    i64 n;
    cin >> n;
    i64 t = 0;
    i64 ans = 1e18;
    for (int i = 1; i <= 10; i++) {
        t = t * 10 + 9;
        i64 x = n;
        i64 cnt = 0;
        while (1) {
            string xx = to_string(x);
            if (xx.find('7') != string::npos) {
                ans = min(ans, cnt);
                break;
            }
            cnt++;
            x += t;
            // cout << x << ' ' << t << '\n';
        }
    }
    cout << ans << '\n';
}

int main ()
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