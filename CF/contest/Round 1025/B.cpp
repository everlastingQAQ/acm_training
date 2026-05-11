#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    auto cal = [&] (i64 a, i64 b) -> i64 {
        return ceil(log2(a)) + ceil(log2(b));
    };

    i64 ans = min({cal(n - a + 1, m), cal(a, m), cal(n, m - b + 1), cal(n, b)}) + 1;

    cout << ans << '\n';
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