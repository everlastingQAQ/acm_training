#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    i64 k, n;
    cin >> n >> k;
    i64 t = sqrtl(n);
    if (t * t != n) t++;
    i64 l = k / t;
    if (l * t == k) {
        cout << l << ' ' << t << '\n';
        return;
    }
    i64 r = k - t * l;
    cout << l + 1 << ' ' << r << '\n';
}

int main ()
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