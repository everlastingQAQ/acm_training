#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

void solve ()
{
    i64 n;
    cin >> n;
    if (n == 1) {
        cout << 1 << '\n';
        return;
    }
    i64 l = 1, r = 1e10;
    i64 ans = 0;
    while (l <= r) {
        i64 mid = l + ((r - l) >> 1);
        i128 sum = (1 + mid) * (mid) / 2 + 1;
        if (sum <= n) {
            ans = mid;
            l = mid + 1;
        }else {
            r = mid - 1;
        }
    } 
    cout << ans + 1 << '\n';
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}