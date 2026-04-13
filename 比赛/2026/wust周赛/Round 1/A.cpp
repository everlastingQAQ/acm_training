#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    i64 x;
    cin >> x;
    auto f = [&] (i64 x) -> i64 {
        return x * x + 2 * x + 3;
    };
    i64 ans = f(f(f(x) + x) + f(f(x)));
    cout << ans << '\n';                                                
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