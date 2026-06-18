#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int l, r, L, R;
    cin >> l >> r >> L >> R;
    int ans;
    if (l < L) {
        if (r < L) {
            ans = 1;
        }else if (r == L) {
            ans = 2;
        }else if (L < r && r < R) {
            ans = r - L + 2;
        }else if (r == R) {
            ans = R - L + 1;
        }else {
            ans = R - L + 2;
        }
    }else if (l == L) {
        if (r < R) {
            ans = r - l + 1;
        }else if (r == R) {
            ans = R - L;
        }else {
            ans = R - L + 1;
        }
    }else if (L < l && l < R) {
        if (r < R) {
            ans = r - l + 2;
        }else if (r == R) {
            ans = r - l + 1;
        }else {
            ans = R - l + 2;
        }
    }else if (l == R) {
        ans = 2;
    }else {
        ans = 1;
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