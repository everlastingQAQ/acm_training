#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
	int a, b, c, l, r;
    cin >> a >> b >> c >> l >> r;
    int ans = r - l + 1;
    if (a >= l && a <= r) ans--;
    if (b != a && b >= l && b <= r) ans--;
    if (c != a && c != b && c >= l && c <= r) ans--;
    cout << ans;
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