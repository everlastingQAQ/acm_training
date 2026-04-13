#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    i64 n;
    cin >> n;
    if (n == 2) {
        cout << 1 << '\n';
        return;
    }
    int cnt = 0;
    for (int i = 63; i >= 0; i--) {
        if (n >> i & 1) {
            cnt++;
        }
    }
    if (cnt == 1) {
        cout << n << '\n';
        return;
    }
    for (int i = 63; i >= 0; i--) {
        if (n >> i & 1) {
            i64 ans = (1LL << (i + 1));
            cout << ans << '\n';
            return;
        }
    }
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